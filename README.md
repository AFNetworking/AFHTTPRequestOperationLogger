# AFHTTPRequestOperationLogger

`AFHTTPRequestOperationLogger` is an extension for [AFNetworking 1.x](http://github.com/AFNetworking/AFNetworking/) that logs HTTP requests as they are sent and received.

### If you are looking for an AFNetworking 2-compatible logger, check out [AFNetworkActivityLogger](https://github.com/AFNetworking/AFNetworkActivityLogger)

> `AFHTTPRequestOperationLogger` listens for `AFNetworkingOperationDidStartNotification` and `AFNetworkingOperationDidFinishNotification` notifications, which are posted by AFNetworking as request operations are started and finish. For further customization of logging output, users are encouraged to implement desired functionality by listening for these notifications.

## Usage

Add the following code to `AppDelegate.m -application:didFinishLaunchingWithOptions:`:

``` objective-c
[[AFHTTPRequestOperationLogger sharedLogger] startLogging];
```

Now all `AFHTTPRequestOperation` will have their request and response logged to the console, a la:

```
GET http://example.com/foo/bar.json
200 http://example.com/foo/bar.json
```

If the default logging level is too verbose—say, if you only want to know when requests fail, then changing it is as simple as:

``` objective-c
[[AFHTTPRequestOperationLogger sharedLogger] setLevel:AFLoggerLevelError];
```

## Contact

Mattt Thompson

- http://github.com/mattt
- http://twitter.com/mattt
- m@mattt.me

## License

AFHTTPRequestOperationLogger is available under the MIT license. See the LICENSE file for more info.
