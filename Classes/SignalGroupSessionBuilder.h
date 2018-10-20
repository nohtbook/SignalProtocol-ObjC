@import Foundation;
#import "SignalContext.h"
#import "SignalSKDM.h"
#import "SignalSenderKeyName.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalGroupSessionBuilder : NSObject

@property (readonly, nonatomic) SignalContext *context;

- (instancetype)initWithContext:(SignalContext *)context;

- (BOOL)processSessionWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                                   skdm:(SignalSKDM *)skdm
                                  error:(NSError **)error;
- (nullable SignalSKDM *)createSessionWithSenderKeyName:(SignalSenderKeyName *)senderKeyName
                                                                          error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
