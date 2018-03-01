@import Foundation;
#import "SignalStorage.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalContext : NSObject

@property (readonly, nonatomic) SignalStorage *storage;

- (nullable instancetype) initWithStorage:(SignalStorage*)storage;

@end

NS_ASSUME_NONNULL_END
