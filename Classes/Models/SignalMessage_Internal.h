#import "SignalMessage.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalMessage ()

@property (readonly, nonatomic) signal_message *signal_message;

@end

NS_ASSUME_NONNULL_END
