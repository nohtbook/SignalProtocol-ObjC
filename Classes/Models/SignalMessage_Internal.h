#import "SignalMessage.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN
@interface SignalMessage ()

@property (nonatomic, readonly) signal_message *signal_message;

@end
NS_ASSUME_NONNULL_END