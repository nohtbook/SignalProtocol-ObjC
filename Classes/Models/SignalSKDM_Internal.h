#import "SignalSKDM.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalSKDM ()

@property (readonly, nonatomic) sender_key_distribution_message *skdm;

- (instancetype)initWithSKDM:(sender_key_distribution_message *)skdm;

@end

NS_ASSUME_NONNULL_END
