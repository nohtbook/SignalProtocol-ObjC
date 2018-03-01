@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface SignalKeyPair : NSObject <NSSecureCoding>

@property (readonly, nonatomic) NSData *publicKey;
@property (readonly, nonatomic) NSData *privateKey;

- (nullable instancetype)initWithPublicKey:(NSData *)publicKey
                                privateKey:(NSData *)privateKey
                                     error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
