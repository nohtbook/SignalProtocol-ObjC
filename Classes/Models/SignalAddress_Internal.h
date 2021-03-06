#import "SignalAddress.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalAddress ()

@property (readonly, nonatomic) signal_protocol_address *address;

- (nullable instancetype)initWithAddress:(const signal_protocol_address *)address;

@end

NS_ASSUME_NONNULL_END
