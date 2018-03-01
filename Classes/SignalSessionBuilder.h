@import Foundation;
#import "SignalAddress.h"
#import "SignalContext.h"
#import "SignalPreKeyBundle.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalSessionBuilder : NSObject

@property (nonatomic, strong, readonly) SignalAddress *address;
@property (nonatomic, strong, readonly) SignalContext *context;

- (instancetype) initWithAddress:(SignalAddress*)address
                         context:(SignalContext*)context;

- (BOOL) processPreKeyBundle:(SignalPreKeyBundle*)preKeyBundle error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
