#import "SignalSignedPreKey.h"
@import SignalProtocolC;

NS_ASSUME_NONNULL_BEGIN

@interface SignalSignedPreKey ()

@property (readonly, nonatomic) session_signed_pre_key *signed_pre_key;

- (instancetype)initWithSignedPreKey:(session_signed_pre_key *)signed_pre_key;

@end

NS_ASSUME_NONNULL_END
