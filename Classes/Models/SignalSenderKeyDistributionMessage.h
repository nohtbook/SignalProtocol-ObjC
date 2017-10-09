@import Foundation;
#import "SignalContext.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalSenderKeyDistributionMessage : NSObject

- (nullable instancetype)initWithData:(NSData *)data
                              context:(SignalContext *)context
                                error:(NSError **)error;

- (NSData *)serializedData;

@end

NS_ASSUME_NONNULL_END
