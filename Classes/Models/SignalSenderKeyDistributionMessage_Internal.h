#import "SignalSenderKeyDistributionMessage.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalSenderKeyDistributionMessage ()

@property (readonly, nonatomic) sender_key_distribution_message *sender_key_distribution_message;

- (instancetype)initWithSenderKeyDistributionMessage:(sender_key_distribution_message *)sender_key_distribution_message;

@end

NS_ASSUME_NONNULL_END
