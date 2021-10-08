//
//  DeviceOrientationObserver.h
//  SDKTest
//
//  Created by 胡勤超 on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
typedef void(^DeviceOrientationObserverBlock)(UIDeviceOrientation orientation);
typedef void(^DeviceOrientationObserverDescriptionBlock)(NSString *description);

@interface DeviceOrientationObserver : NSObject
- (void)startOrientationObserverChangeWithBlock: (DeviceOrientationObserverBlock)orientationBlock;
- (void)startOrientationObserverChangeWithDescriptionBlock: (DeviceOrientationObserverDescriptionBlock)orientationBlock;

- (void)removeOrientationObserver;
@end

NS_ASSUME_NONNULL_END
