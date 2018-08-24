#import "MGLLoggingConfiguration.h"

#define mgl_log_info(message, ...)  mgl_log_with_type(MGLLoggingLevelInfo, __PRETTY_FUNCTION__, __LINE__, message, ##__VA_ARGS__)
#define mgl_log_debug(message, ...) mgl_log_with_type(MGLLoggingLevelDebug, __PRETTY_FUNCTION__, __LINE__, message, ##__VA_ARGS__)
#define mgl_log_error(message, ...) mgl_log_with_type(MGLLoggingLevelError, __PRETTY_FUNCTION__, __LINE__, message, ##__VA_ARGS__)
#define mgl_log_fault(message, ...) mgl_log_with_type(MGLLoggingLevelFault, __PRETTY_FUNCTION__, __LINE__, message, ##__VA_ARGS__)
#define mgl_log_with_type(type, function, line, message, ...) \
{ \
    if ([MGLLoggingConfiguration sharedConfiguration].loggingLevel != MGLLoggingLevelNone && type <= [MGLLoggingConfiguration sharedConfiguration].loggingLevel) \
    { \
        [[MGLLoggingConfiguration sharedConfiguration] logCallingFunction:function functionLine:line messageType:type format:(message), ##__VA_ARGS__]; \
    } \
}

@interface MGLLoggingConfiguration (Private)

- (void)logCallingFunction:(const char *)callingFunction functionLine:(NSUInteger)functionLine messageType:(MGLLoggingLevel)type format:(id)messageFormat, ...;

@end
