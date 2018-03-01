@import Foundation;
#import "SignalAddress.h"
#import "SignalCiphertext.h"
#import "SignalContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalSessionCipher : NSObject

@property (readonly, nonatomic) SignalAddress *address;
@property (readonly, nonatomic) SignalContext *context;

- (instancetype) initWithAddress:(SignalAddress*)address
                         context:(SignalContext*)context;

- (nullable SignalCiphertext*)encryptData:(NSData*)data error:(NSError**)error;
- (nullable NSData*)decryptCiphertext:(SignalCiphertext*)ciphertext error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
