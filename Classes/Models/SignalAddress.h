@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface SignalAddress : NSObject

@property (readonly, nonatomic) NSString *name;
@property (readonly, nonatomic) int32_t deviceId;

- (instancetype) initWithName:(NSString*)name
                     deviceId:(int32_t)deviceId;

@end

NS_ASSUME_NONNULL_END
