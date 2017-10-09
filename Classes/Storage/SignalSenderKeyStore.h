@import Foundation;
#import "SignalSenderKeyName.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SignalSenderKeyStore <NSObject>

@required

/**
 * Store a serialized sender key record for a given
 * (groupId + senderId + deviceId) tuple.
 */
- (BOOL)storeSenderKey:(NSData *)senderKey senderKeyName:(SignalSenderKeyName *)senderKeyName;

/**
 * Returns a copy of the sender key record corresponding to the
 * (groupId + senderId + deviceId) tuple.
 */
- (nullable NSData *)loadSenderKeyForSenderKeyName:(SignalSenderKeyName *)senderKeyName;

@end

NS_ASSUME_NONNULL_END
