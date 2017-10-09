#import "SignalGroupCipher.h"
#import "SignalContext_Internal.h"
#import "SignalError.h"
#import "SignalSenderKeyMessage_Internal.h"
#import "SignalSenderKeyName_Internal.h"
#import "SignalStorage_Internal.h"

@interface SignalGroupCipher ()
@property (readonly, nonatomic) group_cipher *cipher;
@end

@implementation SignalGroupCipher

- (instancetype)initWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                              context:(SignalContext *)context {
    NSParameterAssert(senderKeyName);
    NSParameterAssert(context);
    if (!senderKeyName || !context) { return nil; }
    if (self = [super init]) {
        _context = context;
        int result = group_cipher_create(&_cipher, context.storage.storeContext, senderKeyName.sender_key_name, context.context);
        NSAssert(result >= 0 && _cipher, @"couldn't create cipher");
        if (result < 0 || !_cipher) {
            return nil;
        }
    }
    return self;
}

- (SignalCiphertext *)encryptData:(NSData *)data error:(NSError **)error {
    NSParameterAssert(data);
    if (!data) {
        if (error) {
            *error = ErrorFromSignalError(SignalErrorInvalidArgument);
        }
        return nil;
    }
    ciphertext_message *message = NULL;
    int result = group_cipher_encrypt(_cipher, data.bytes, data.length, &message);
    if (result < 0 || !message) {
        *error = ErrorFromSignalError(SignalErrorFromCode(result));
        return nil;
    }
    signal_buffer *serialized = ciphertext_message_get_serialized(message);
    NSData *outData = [NSData dataWithBytes:signal_buffer_data(serialized) length:signal_buffer_len(serialized)];
    SignalCiphertextType outType = SignalCiphertextTypeSenderKeyMessage;
    SignalCiphertext *encrypted = [[SignalCiphertext alloc] initWithData:outData type:outType];
    SIGNAL_UNREF(message);
    return encrypted;
}

- (nullable NSData *)decryptCiphertext:(SignalCiphertext *)ciphertext error:(NSError **)error {
    NSParameterAssert(ciphertext && ciphertext.data);
    if (!ciphertext || !ciphertext.data) {
        if (error) {
            *error = ErrorFromSignalError(SignalErrorInvalidArgument);
        }
        return nil;
    }
    SignalSenderKeyMessage *message = [[SignalSenderKeyMessage alloc] initWithData:ciphertext.data context:_context error:error];
    if (!message) { return nil; }
    signal_buffer *buffer = NULL;
    int result = SG_ERR_UNKNOWN;
    result = group_cipher_decrypt(_cipher, message.sender_key_message, NULL, &buffer);
    if (result < 0 || !buffer) {
        if (error) {
            *error = ErrorFromSignalError(SignalErrorFromCode(result));
        }
        return nil;
    }
    NSData *outData = [NSData dataWithBytes:signal_buffer_data(buffer) length:signal_buffer_len(buffer)];
    signal_buffer_free(buffer);
    return outData;
}

@end
