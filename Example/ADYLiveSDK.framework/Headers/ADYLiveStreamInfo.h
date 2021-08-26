//
//  Module:   ADYLiveStreamInfo   @ ADYLiveSDK
//
//  Function: 奥点云直播推流用 RTMP SDK
//
//  Copyright © 2021 杭州奥点科技股份有限公司. All rights reserved.
//
//  Version: 1.1.0  Creation(版本信息)

/**
 * @author   Created by 胡勤超 on 2021/5/26.
 * @instructions 说明
 该类是
 
 * @abstract  奥点官方网站  https://www.aodianyun.com
 
 */



#import <Foundation/Foundation.h>
#if __has_include(<ADYLiveSDK/ADYLiveSDK.h>)
#import <ADYLiveSDK/ADYLiveAudioConfiguration.h>
#import <ADYLiveSDK/ADYLiveVideoConfiguration.h>
#else
#import "ADYLiveAudioConfiguration.h"
#import "ADYLiveVideoConfiguration.h"
#endif

NS_ASSUME_NONNULL_BEGIN


/// 流状态
typedef NS_ENUM (NSUInteger, ADYLiveState){
    /// 准备
    ADYLiveReady = 0,
    /// 连接中
    ADYLivePending = 1,
    /// 已连接
    ADYLiveStart = 2,
    /// 已断开
    ADYLiveStop = 3,
    /// 连接出错
    ADYLiveError = 4,
    ///  正在刷新
    ADYLiveRefresh = 5
};

typedef NS_ENUM (NSUInteger, ADYLiveSocketErrorCode) {
    ADYLiveSocketError_PreView = 201,              ///< 预览失败
    ADYLiveSocketError_GetStreamInfo = 202,        ///< 获取流媒体信息失败
    ADYLiveSocketError_ConnectSocket = 203,        ///< 连接socket失败
    ADYLiveSocketError_Verification = 204,         ///< 验证服务器失败
    ADYLiveSocketError_ReConnectTimeOut = 205      ///< 重新连接服务器超时
};
@interface ADYLiveStreamInfo : NSObject
@property (nonatomic, copy) NSString *streamId;

#pragma mark -- FLV
@property (nonatomic, copy) NSString *host;
@property (nonatomic, assign) NSInteger port;
#pragma mark -- RTMP
@property (nonatomic, copy) NSString *url;          ///< 上传地址 (RTMP用就好了)
///音频配置
@property (nonatomic, strong) ADYLiveAudioConfiguration *audioConfiguration;
///视频配置
@property (nonatomic, strong) ADYLiveVideoConfiguration *videoConfiguration;
@end

NS_ASSUME_NONNULL_END
