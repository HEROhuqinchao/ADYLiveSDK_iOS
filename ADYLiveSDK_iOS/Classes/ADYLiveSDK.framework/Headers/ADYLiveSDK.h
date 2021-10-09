//
//  ADYLiveSDK.h
//  ADYLiveSDK
//
//  Created by 胡勤超 on 2021/5/24.
//

#import <Foundation/Foundation.h>

//! Project version number for ADYLiveSDK.
FOUNDATION_EXPORT double ADYLiveSDKVersionNumber;

//! Project version string for ADYLiveSDK.
FOUNDATION_EXPORT const unsigned char ADYLiveSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ADYLiveSDK/PublicHeader.h>

#ifndef ADYLiveSDK_h
#define ADYLiveSDK_h

#if __has_include(<ADYLiveSDK/ADYLiveSDK.h>)
#import <ADYLiveSDK/ADYLiveSession.h>
#import <ADYLiveSDK/ADYLiveAudioConfiguration.h>
#import <ADYLiveSDK/ADYLiveVideoConfiguration.h>
#import <ADYLiveSDK/ADYAudioFrame.h>
#import <ADYLiveSDK/ADYFrame.h>
#import <ADYLiveSDK/ADYLiveStreamInfo.h>
#import <ADYLiveSDK/ADYVideoFrame.h>
#import <ADYLiveSDK/ADYLiveDebug.h>
#import <ADYLiveSDK/DeviceOrientationObserver.h>
#else
#import "ADYLiveSession.h"
#import "ADYLiveAudioConfiguration.h"
#import "ADYLiveVideoConfiguration.h"
#import "ADYAudioFrame.h"
#import "ADYFrame.h"
#import "ADYLiveStreamInfo.h"
#import "ADYVideoFrame.h"
#import "ADYLiveDebug.h"
#import "DeviceOrientationObserver.h"
#endif

#endif
