// AFHTTPRequestLogger.h
//
// Copyright (c) 2011 Mattt Thompson (http://mattt.me/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
 The following constants are provided by `AFHTTPRequestOperationLogger` as possible options to set verbosity level.
 The default option is `AFLoggerLevelInfo`.
 
 enum {
    AFLoggerLevelOff,
    AFLoggerLevelDebug,
    AFLoggerLevelInfo,
    AFLoggerLevelWarn,
    AFLoggerLevelError,
    AFLoggerLevelFatal = AFLoggerLevelOff,
 }

 `AFLoggerLevelOff`
    Turns off any logging

 `AFLoggerLevelDebug`
    Shows HTTP header and body for request and response in addition to `AFLoggerLevelInfo` verbose level.

 `AFLoggerLevelInfo`
    Default verbose level. Logs request and response to the console like this:

    ```
    GET http://example.com/foo/bar.json
    200 http://example.com/foo/bar.json
    ```

 `AFLoggerLevelWarn`
    Only warn when error occured

 `AFLoggerLevelError`
    By far the same as `AFLoggerLevelWarn`

 `AFLoggerLevelFatal`
    Same as `AFLoggerLevelOff`

 */
typedef enum {
  AFLoggerLevelOff,
  AFLoggerLevelDebug,
  AFLoggerLevelInfo,
  AFLoggerLevelWarn,
  AFLoggerLevelError,
  AFLoggerLevelFatal = AFLoggerLevelOff,
} AFHTTPRequestLoggerLevel;

/**
AFHTTPRequestOperationLogger is an extension for [AFNetworking](http://github.com/AFNetworking/AFNetworking/) that logs HTTP requests as they are sent and received.
 */
@interface AFHTTPRequestOperationLogger : NSObject

/**
 Verbosity level. Default is `AFLoggerLevelInfo`.
 */
@property (nonatomic, assign) AFHTTPRequestLoggerLevel level;

/**
 Predicate object which is used to ignore any operation that matches the provided criteria.

 Pass predicate object, which will be used to ignore any operation that matches the provided criteria and allow all through if no predicate is passed. Predicate is evaluated agains `AFHTTPRequestOperation` object. Default is `nil`.
 */
@property (nonatomic, strong) NSPredicate *filterPredicate;

/**
 Returns the shared operation logger object.
 */
+ (AFHTTPRequestOperationLogger *)sharedLogger;

/**
 Starts loggin HTTP requests which are performed by `AFHTTPRequestOperation` objects.
 */
- (void)startLogging;

/**
 Stops loggin HTTP requests which are performed by `AFHTTPRequestOperation` objects.
 */
- (void)stopLogging;

@end
