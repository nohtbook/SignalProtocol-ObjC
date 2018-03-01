@import Foundation;
#import "SignalKeyPair.h"
#import "SignalSerializable.h"

NS_ASSUME_NONNULL_BEGIN
@interface SignalPreKey : NSObject <SignalSerializable, NSSecureCoding>

@property (nonatomic, readonly) uint32_t preKeyId;
@property (nonatomic, readonly, nullable)  SignalKeyPair* keyPair;

@end
NS_ASSUME_NONNULL_END
