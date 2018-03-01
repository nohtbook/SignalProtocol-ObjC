#import "SignalContext.h"
@import SignalProtocolC;

@interface SignalContext ()

@property (nonatomic, readonly) signal_context *context;
@property (nonatomic, strong, readonly) NSRecursiveLock *lock;

@end
