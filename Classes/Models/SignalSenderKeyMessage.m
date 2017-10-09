#import "SignalSenderKeyMessage_Internal.h"
#import "SignalContext_Internal.h"
#import "SignalError.h"

@implementation SignalSenderKeyMessage

- (void)dealloc {
    if (_sender_key_message) {
        SIGNAL_UNREF(_sender_key_message);
    }
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
        int result = sender_key_message_deserialize(&_sender_key_message, data.bytes, data.length, context.context);
        if (result < 0 || !_sender_key_message) {
            if (error) {
                *error = ErrorFromSignalError(SignalErrorFromCode(result));
            }
            return nil;
        }
    }
    return self;
}

@end
