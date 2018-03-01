#import "SignalPreKey.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalPreKey ()

@property (nonatomic, readonly) session_pre_key *preKey;

- (instancetype) initWithPreKey:(session_pre_key*)preKey;

@end

NS_ASSUME_NONNULL_END
