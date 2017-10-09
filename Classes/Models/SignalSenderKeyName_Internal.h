#import "SignalSenderKeyName.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalSenderKeyName ()

@property (readonly, nonatomic) signal_protocol_sender_key_name *sender_key_name;

- (nullable instancetype)initWithSenderKeyName:(const signal_protocol_sender_key_name *)sender_key_name;

@end

NS_ASSUME_NONNULL_END
