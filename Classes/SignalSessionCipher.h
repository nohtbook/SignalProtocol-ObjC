@import Foundation;
#import "SignalAddress.h"
#import "SignalCiphertext.h"
#import "SignalContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalSessionCipher : NSObject

- (instancetype)initWithAddress:(SignalAddress *)address context:(SignalContext *)context;

- (nullable SignalCiphertext *)encryptData:(NSData *)data error:(NSError **)error;
- (nullable NSData *)decryptCiphertext:(SignalCiphertext *)ciphertext error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
