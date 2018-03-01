@import Foundation;
#import "SignalContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalPreKeyMessage : NSObject

- (nullable instancetype) initWithData:(NSData*)data
                               context:(SignalContext*)context
                                 error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
