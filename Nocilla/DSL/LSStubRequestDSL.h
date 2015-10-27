#import <Foundation/Foundation.h>
#import "NSString+Matcheable.h"
#import "NSRegularExpression+Matcheable.h"
#import "NSData+Matcheable.h"

@class LSStubRequestDSL;
@class LSStubResponseDSL;
@class LSStubRequest;

@protocol LSHTTPBody;

typedef LSStubRequestDSL *(^WithHeaderMethod)(NSString *, NSString *);
typedef LSStubRequestDSL *(^WithHeadersMethod)(NSDictionary *);
typedef LSStubRequestDSL *(^WithCookieMethod)(NSString *, NSString *);
typedef LSStubRequestDSL *(^WithCookiesMethod)(NSDictionary *);
typedef LSStubRequestDSL *(^AndBodyMethod)(id<LSMatcheable>);
typedef LSStubResponseDSL *(^AndReturnMethod)(NSInteger);
typedef LSStubResponseDSL *(^AndReturnRawResponseMethod)(NSData *rawResponseData);
typedef void (^AndFailWithErrorMethod)(NSError *error);

@interface LSStubRequestDSL : NSObject
- (id)initWithRequest:(LSStubRequest *)request;

@property (nonatomic, strong, readonly) WithHeaderMethod withHeader;
@property (nonatomic, strong, readonly) WithHeadersMethod withHeaders;
@property (nonatomic, strong, readonly) WithCookieMethod withCookie;
@property (nonatomic, strong, readonly) WithCookiesMethod withCookies;
@property (nonatomic, strong, readonly) AndBodyMethod withBody;
@property (nonatomic, strong, readonly) AndReturnMethod andReturn;
@property (nonatomic, strong, readonly) AndReturnMethod andReturnWithStatusCode;
@property (nonatomic, strong, readonly) AndReturnRawResponseMethod andReturnRawResponse;
@property (nonatomic, strong, readonly) AndFailWithErrorMethod andFailWithError;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
LSStubRequestDSL * stubRequest(NSString *method, id<LSMatcheable> url);
    
#ifdef __cplusplus
}
#endif
