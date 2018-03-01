#import "SignalIdentityKeyPair.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalIdentityKeyPair ()

@property (readonly, nonatomic) ratchet_identity_key_pair *identity_key_pair;

- (instancetype) initWithIdentityKeyPair:(ratchet_identity_key_pair*)identity_key_pair;

@end

NS_ASSUME_NONNULL_END
