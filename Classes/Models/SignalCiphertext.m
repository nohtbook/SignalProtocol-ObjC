#import "SignalCiphertext.h"

@implementation SignalCiphertext

- (instancetype) initWithData:(NSData*)data
                         type:(SignalCiphertextType)type {
    NSParameterAssert(data);
    if (!data) { return nil; }
    if (self = [super init]) {
        _data = data;
        _type = type;
    }
    return self;
}

@end
