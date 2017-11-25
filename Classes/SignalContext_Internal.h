#import "SignalContext.h"
#import "SignalCommonCryptoProvider.h"
@import SignalProtocolC;

@interface SignalContext ()
@property (nonatomic, readonly) signal_context *context;
@property (nonatomic, strong, readonly) NSRecursiveLock *lock;
@end