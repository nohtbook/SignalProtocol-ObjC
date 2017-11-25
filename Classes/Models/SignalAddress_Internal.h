#import "SignalAddress.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN
@interface SignalAddress ()

@property (nonatomic, readonly) signal_protocol_address *address;

- (nullable instancetype) initWithAddress:(nonnull const signal_protocol_address*)address;

@end
NS_ASSUME_NONNULL_END