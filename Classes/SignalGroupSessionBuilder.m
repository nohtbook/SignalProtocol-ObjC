#import "SignalGroupSessionBuilder.h"
#import "SignalContext_Internal.h"
#import "SignalError.h"
#import "SignalSKDM_Internal.h"
#import "SignalSenderKeyName_Internal.h"
#import "SignalStorage_Internal.h"

@interface SignalGroupSessionBuilder ()
@property (readonly, nonatomic) group_session_builder *builder;
@end

@implementation SignalGroupSessionBuilder

- (void)dealloc {
    if (_builder) {
        group_session_builder_free(_builder);
    }
    _builder = NULL;
}

- (instancetype)initWithContext:(SignalContext *)context {
    NSParameterAssert(context);
    if (!context) { return nil; }
    if (self = [super init]) {
        _context = context;
        int result = group_session_builder_create(&_builder, context.storage.storeContext, context.context);
        NSAssert(result == 0 && _builder, @"couldn't create builder");
        if (result < 0 || !_builder) {
            return nil;
        }
    }
    return self;
}

- (BOOL)processSessionWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                                   skdm:(SignalSKDM *)skdm
                                  error:(NSError **)error {
    NSParameterAssert(senderKeyName);
    NSParameterAssert(skdm);
    if (!senderKeyName || !skdm) {
        if (error) {
            *error = ErrorFromSignalError(SignalErrorInvalidArgument);
        }
        return NO;
    }
    int result = group_session_builder_process_session(_builder, senderKeyName.sender_key_name, skdm.skdm);
    if (result < 0) {
        if (error) {
            *error = ErrorFromSignalError(result);
        }
        return NO;
    }
    return YES;
}

- (SignalSKDM *)createSessionWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                                                                 error:(NSError **)error {
    NSParameterAssert(senderKeyName);
    if (!senderKeyName) {
        if (error) {
            *error = ErrorFromSignalError(SignalErrorInvalidArgument);
        }
        return nil;
    }
    sender_key_distribution_message *skdm = NULL;
    int result = group_session_builder_create_session(_builder, &skdm, senderKeyName.sender_key_name);
    if (result < 0 || !skdm) {
        *error = ErrorFromSignalError(SignalErrorFromCode(result));
        return nil;
    }
    return [[SignalSKDM alloc] initWithSKDM:skdm];
}

@end
