#import "SignalAddress.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalSenderKeyName : NSObject

@property (readonly, copy, nonatomic) NSString *groupId;
@property (readonly, nonatomic) SignalAddress *address;

- (instancetype)initWithGroupId:(NSString *)groupId address:(SignalAddress *)address;

@end

NS_ASSUME_NONNULL_END
