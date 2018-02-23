#import "SignalKeyPair.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalKeyPair ()

@property (readonly, nonatomic) ec_key_pair *ec_key_pair;
@property (readonly, nonatomic) ec_public_key* ec_public_key;
@property (readonly, nonatomic) ec_private_key* ec_private_key;

- (nullable instancetype)initWithECKeyPair:(ec_key_pair *)ec_key_pair;
- (nullable instancetype)initWithECPublicKey:(ec_public_key *)ec_public_key
                                ecPrivateKey:(ec_private_key *)ec_private_key;

/** make sure to call SIGNAL_UNREF when you're done */
+ (nullable ec_public_key *)publicKeyFromData:(NSData *)data error:(NSError **)error;
+ (nullable ec_private_key *)privateKeyFromData:(NSData *)data error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
