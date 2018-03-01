@import Foundation;
#import "SignalKeyPair.h"
#import "SignalSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalPreKey : NSObject <SignalSerializable, NSSecureCoding>

@property (readonly, nonatomic) uint32_t preKeyId;
@property (readonly, nonatomic, nullable)  SignalKeyPair* keyPair;

@end

NS_ASSUME_NONNULL_END
