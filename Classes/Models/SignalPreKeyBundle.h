@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface SignalPreKeyBundle : NSObject

@property (readonly, nonatomic) uint32_t registrationId;
@property (readonly, nonatomic) uint32_t deviceId;
@property (readonly, nonatomic) uint32_t preKeyId;
@property (readonly, nonatomic) NSData *preKeyPublic;
@property (readonly, nonatomic) uint32_t signedPreKeyId;
@property (readonly, nonatomic) NSData *signedPreKeyPublic;
@property (readonly, nonatomic) NSData *signature;
@property (readonly, nonatomic) NSData *identityKey;

- (nullable instancetype) initWithRegistrationId:(uint32_t)registrationId
                               deviceId:(uint32_t)deviceId
                               preKeyId:(uint32_t)preKeyId
                           preKeyPublic:(NSData*)preKeyPublic
                         signedPreKeyId:(uint32_t)signedPreKeyId
                     signedPreKeyPublic:(NSData*)signedPreKeyPublic
                              signature:(NSData*)signature
                            identityKey:(NSData*)identityKey
                                  error:(NSError* __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
