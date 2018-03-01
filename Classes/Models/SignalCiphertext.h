@import Foundation;

typedef NS_ENUM(NSInteger, SignalCiphertextType) {
    SignalCiphertextTypeUnknown,
    SignalCiphertextTypeMessage,
    SignalCiphertextTypePreKeyMessage
};

NS_ASSUME_NONNULL_BEGIN

@interface SignalCiphertext : NSObject

@property (readonly, nonatomic) SignalCiphertextType type;
@property (readonly, nonatomic) NSData *data;

- (instancetype)initWithData:(NSData *)data type:(SignalCiphertextType)type;

@end

NS_ASSUME_NONNULL_END
