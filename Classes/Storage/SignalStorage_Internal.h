#import "SignalStorage.h"
@import SignalProtocolC;

@interface SignalStorage ()

@property (readonly, nonatomic) id<SignalSessionStore> sessionStore;
@property (readonly, nonatomic) id<SignalPreKeyStore> preKeyStore;
@property (readonly, nonatomic) id<SignalSignedPreKeyStore> signedPreKeyStore;
@property (readonly, nonatomic) id<SignalIdentityKeyStore> identityKeyStore;
@property (readonly, nonatomic) id<SignalSenderKeyStore> senderKeyStore;
@property (readonly, nonatomic) signal_protocol_store_context *storeContext;

- (void) setupWithContext:(signal_context*)context;

@end
