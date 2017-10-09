@import Foundation;
#import "SignalContext.h"
#import "SignalSenderKeyDistributionMessage.h"
#import "SignalSenderKeyName.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalGroupSessionBuilder : NSObject

@property (readonly, nonatomic) SignalContext *context;

- (instancetype)initWithContext:(SignalContext *)context;

- (BOOL)processSessionWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
           senderKeyDistributionMessage:(SignalSenderKeyDistributionMessage *)senderKeyDistributionMessage
                                  error:(NSError **)error;
- (nullable SignalSenderKeyDistributionMessage *)createSessionWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                                                                          error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
