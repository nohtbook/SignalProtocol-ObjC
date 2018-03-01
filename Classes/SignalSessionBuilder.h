@import Foundation;
#import "SignalAddress.h"
#import "SignalContext.h"
#import "SignalPreKeyBundle.h"

NS_ASSUME_NONNULL_BEGIN

@interface SignalSessionBuilder : NSObject

@property (readonly, nonatomic) SignalAddress *address;
@property (readonly, nonatomic) SignalContext *context;

- (instancetype)initWithAddress:(SignalAddress *)address context:(SignalContext *)context;

- (BOOL)processPreKeyBundle:(SignalPreKeyBundle *)preKeyBundle error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
