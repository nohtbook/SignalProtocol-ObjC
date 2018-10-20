#import "SignalSKDM_Internal.h"
#import "SignalContext_Internal.h"
#import "SignalError.h"

@implementation SignalSKDM

- (void)dealloc {
    if (_skdm) {
        SIGNAL_UNREF(_skdm);
    }
}

- (instancetype)initWithSKDM:(sender_key_distribution_message *)skdm {
    NSParameterAssert(skdm);
    if (!skdm) { return nil; }
    if (self = [super init]) {
        _skdm = skdm;
    }
    return self;
}

- (instancetype)initWithData:(NSData *)data
                     context:(SignalContext *)context
                       error:(NSError **)error {
    NSParameterAssert(data);
    NSParameterAssert(context);
    if (!data || !context) {
        if (error) {
            *error = ErrorFromSignalError(SignalErrorInvalidArgument);
        }
        return nil;
    }
    if (self = [super init]) {
        int result = sender_key_distribution_message_deserialize(&_skdm, data.bytes, data.length, context.context);
        if (result < 0 || !_skdm) {
            if (error) {
                *error = ErrorFromSignalError(SignalErrorFromCode(result));
            }
            return nil;
        }
    }
    return self;
}

- (NSData *)serializedData {
    ciphertext_message *message = (ciphertext_message *)_skdm;
    signal_buffer *serialized = ciphertext_message_get_serialized(message);
    return [NSData dataWithBytes:signal_buffer_data(serialized) length:signal_buffer_len(serialized)];
}

@end
