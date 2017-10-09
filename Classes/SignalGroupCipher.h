@import Foundation;
#import "SignalCiphertext.h"
#import "SignalContext.h"
#import "SignalSenderKeyName.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalGroupCipher : NSObject

@property (readonly, nonatomic) SignalContext *context;

- (instancetype)initWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                              context:(SignalContext *)context;

- (nullable SignalCiphertext *)encryptData:(NSData *)data error:(NSError **)error;
- (nullable NSData *)decryptCiphertext:(SignalCiphertext *)ciphertext error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
