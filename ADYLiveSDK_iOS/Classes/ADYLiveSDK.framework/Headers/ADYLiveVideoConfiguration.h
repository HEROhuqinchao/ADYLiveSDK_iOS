//
//  Module:   ADYLiveVideoConfiguration   @ ADYLiveSDK
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
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
/// 默认显示横屏分辨率，竖屏长宽切换即可 。视频分辨率(都是16：9 当此设备不支持当前分辨率，自动降低一级)
typedef NS_ENUM (NSUInteger, ADYLiveVideoSessionPreset){
    /// 低分辨率
    ADYCaptureSessionPreset640x360 = 0,
    /// 中分辨率
    ADYCaptureSessionPreset960x540 = 1,
    /// 高分辨率
    ADYCaptureSessionPreset1280x720 = 2,
    /// 超高分辨率
    ADYCaptureSessionPreset1920x1080 = 3,
    /// 4K UHD分辨率
    ADYCaptureSessionPreset3840x2160 = 4,
};

@interface ADYLiveVideoConfiguration : NSObject<NSCoding, NSCopying>

/**判断是否支持分辨率*/
- (ADYLiveVideoSessionPreset)supportSessionPreset:(ADYLiveVideoSessionPreset)sessionPreset devicePosition:(  AVCaptureDevicePosition )devicePosition;

/**自定义情况下必须进行数据更新*/
- (void)defaultConfiguration:(ADYLiveVideoConfiguration *)configuration;

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================
/// 视频的分辨率，宽高务必设定为 2 的倍数，否则解码播放时可能出现绿边(这个videoSizeRespectingAspectRatio设置为YES则可能会改变)
@property (nonatomic, assign) CGSize videoSize;

/** 美颜设置*/
/** The beautyFace control capture shader filter empty or beautiy */
@property (nonatomic, assign) BOOL beautyFace;

/// 输出图像是否等比例,默认为NO
@property (nonatomic, assign) BOOL videoSizeRespectingAspectRatio;

/** 摄像头位置，默认为前置摄像头AVCaptureDevicePositionFront */
@property (nonatomic, assign) AVCaptureDevicePosition devicePosition;

/// 视频输出方向
@property (nonatomic, assign) UIInterfaceOrientation outputImageOrientation;

/** 摄像头方向 默认为当前手机屏幕方向 */
@property (nonatomic, assign) AVCaptureVideoOrientation videoOrientation;

/** 自动旋转(这里只支持 left 变 right  portrait 变 portraitUpsideDown) */
@property (nonatomic, assign) BOOL autorotate;

/** 是否发送帧同步信息*/
@property (nonatomic, assign) BOOL isSendSEI;

/** 是否开启垫片推流 发送设置图片 默认为false*/
@property (nonatomic, assign) BOOL isSendCloverImage;
/** 是否开启垫片推流 发送设置图片 默认为false*/
@property (nonatomic, readonly) BOOL isSendCustomFrame;

/**
 *  垫片推流设置图片 设置此图片 推流发送此图片
 *  isSendCloverImage =  true 生效
 *  请尽可能设置图片尺寸为直播尺寸 否则内部会进行等比拉伸裁剪 平铺画面
 */
@property (nonatomic, strong) UIImage * _Nullable cloverImage;
/** 直播内部调用*/
@property (nonatomic, assign, readonly) CVPixelBufferRef _Nullable  lastImageBuffer;

/// 视频的帧率，即 fps
@property (nonatomic, assign) NSUInteger videoFrameRate;

/// 视频的最大帧率，即 fps
@property (nonatomic, assign) NSUInteger videoMaxFrameRate;

/// 视频的最小帧率，即 fps
@property (nonatomic, assign) NSUInteger videoMinFrameRate;

/// 最大关键帧间隔，可设定为 fps 的2倍，影响一个 gop 的大小
@property (nonatomic, assign) NSUInteger videoMaxKeyframeInterval;

/// 视频的码率，单位是 bps
@property (nonatomic, assign) NSUInteger videoBitRate;

/// 视频的最大码率，单位是 bps
@property (nonatomic, assign) NSUInteger videoMaxBitRate;

/// 视频的最小码率，单位是 bps
@property (nonatomic, assign) NSUInteger videoMinBitRate;

///< 分辨率
@property (nonatomic, assign) ADYLiveVideoSessionPreset sessionPreset;

///< ≈sde3分辨率
@property (nonatomic, assign, readonly) NSString * _Nullable avSessionPreset;

///< 是否是横屏
@property (nonatomic, assign, readonly) BOOL landscape;



/// 自定义配置
+ (instancetype _Nonnull )customConfiguration_outputImageOrientation:(BOOL)landscape;

/// 默认分辨率： 1080 *1920  帧数：30 码率：3000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_Default;

/// 分辨率： 360 *640 帧数：24 码率：500Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_360P_24FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 360 *640 帧数：30 码率：800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_360P_30FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 360 *640 帧数：60 码率：800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_360P_60FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 540 *960 帧数：24 码率：800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_540P_24FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 540 *960 帧数：30 码率：800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_540P_30FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 540 *960 帧数：60 码率：800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_540P_60FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 720 *1280 帧数：24 码率：1200Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_720P_24FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 720 *1280 帧数：30 码率：1800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_720P_30FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 720 *1280 帧数：60 码率：1800Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_720P_60FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 1080 *1920 帧数：24 码率：3000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_1080P_24FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 1080 *1920  帧数：30 码率：3000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_1080P_30FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 1080 *1920  帧数：60 码率：3000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_1080P_60FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 2160 *3840 帧数：15 码率：8000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_2160P_15FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 2160 *3840 帧数：24 码率：8000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_2160P_24FPS_outputImageOrientation:(BOOL)landscape;

/// 分辨率： 2160 *3840 帧数：30 码率：8000Kps
+ (instancetype _Nonnull )ADYLiveVideoQuality_2160P_30FPS_outputImageOrientation:(BOOL)landscape;

@end
