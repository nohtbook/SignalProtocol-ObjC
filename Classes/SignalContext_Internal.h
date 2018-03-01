#import "SignalContext.h"
@import SignalProtocolC;

@interface SignalContext ()

@property (readonly, nonatomic) signal_context *context;
@property (readonly, nonatomic) NSRecursiveLock *lock;

@end
