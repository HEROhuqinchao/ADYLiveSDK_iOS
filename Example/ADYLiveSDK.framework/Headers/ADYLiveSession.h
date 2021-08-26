//
//  Module:   ADYLiveSession   @ ADYLiveSDK
//
//  Function: 奥点云直播推流用 RTMP SDK
//
//  Copyright © 2021 杭州奥点科技股份有限公司. All rights reserved.
//
//  Version: 1.1.0  Creation(版本信息)

/**
 * @author   Created by 胡勤超 on 2021/5/26.
 * @instructions 说明
 该类是 SDK 控制器
 
 * @abstract  奥点官方网站  https://www.aodianyun.com
 
 */



#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#if __has_include(<ADYLiveSDK/ADYLiveSDK.h>)
#import <ADYLiveSDK/ADYLiveStreamInfo.h>
#import <ADYLiveSDK/ADYAudioFrame.h>
#import <ADYLiveSDK/ADYVideoFrame.h>
#import <ADYLiveSDK/ADYLiveAudioConfiguration.h>
#import <ADYLiveSDK/ADYLiveVideoConfiguration.h>
#import <ADYLiveSDK/ADYLiveDebug.h>
#else
#import "ADYLiveStreamInfo.h"
#import "ADYAudioFrame.h"
#import "ADYVideoFrame.h"
#import "ADYLiveAudioConfiguration.h"
#import "ADYLiveVideoConfiguration.h"
#import "ADYLiveDebug.h"

#endif

typedef NS_ENUM(NSInteger,ADYLiveCaptureType) {
    ADYLiveCaptureAudio,         ///< capture only audio
    ADYLiveCaptureVideo,         ///< capture onlt video
    ADYLiveInputAudio,           ///< only audio (External input audio)
    ADYLiveInputVideo,           ///< only video (External input video)
};


///< 用来控制采集类型（可以内部采集也可以外部传入等各种组合，支持单音频与单视频,外部输入适用于录屏，无人机等外设接入）
typedef NS_ENUM(NSInteger,ADYLiveCaptureTypeMask) {
    ADYLiveCaptureMaskAudio = (1 << ADYLiveCaptureAudio),                                 ///< only inner capture audio (no video)
    ADYLiveCaptureMaskVideo = (1 << ADYLiveCaptureVideo),                                 ///< only inner capture video (no audio)
    ADYLiveInputMaskAudio = (1 << ADYLiveInputAudio),                                     ///< only outer input audio (no video)
    ADYLiveInputMaskVideo = (1 << ADYLiveInputVideo),                                     ///< only outer input video (no audio)
    ADYLiveCaptureMaskAll = (ADYLiveCaptureMaskAudio | ADYLiveCaptureMaskVideo),           ///< inner capture audio and video
    ADYLiveInputMaskAll = (ADYLiveInputMaskAudio | ADYLiveInputMaskVideo),                 ///< outer input audio and video(method see pushVideo and pushAudio)
    ADYLiveCaptureMaskAudioInputVideo = (ADYLiveCaptureMaskAudio | ADYLiveInputMaskVideo), ///< inner capture audio and outer input video(method pushVideo and setRunning)
    ADYLiveCaptureMaskVideoInputAudio = (ADYLiveCaptureMaskVideo | ADYLiveInputMaskAudio), ///< inner capture video and outer input audio(method pushAudio and setRunning)
    ADYLiveCaptureDefaultMask = ADYLiveCaptureMaskAll                                     ///< default is inner capture audio and video
};

@class ADYLiveSession;
@protocol ADYLiveSessionDelegate <NSObject>

@optional
/** live status changed will callback --实时状态更改将回调 */
- (void)liveSession:(nullable ADYLiveSession *)session liveStateDidChange:(ADYLiveState)state;
/** live debug info callback --直播信息回调 */
- (void)liveSession:(nullable ADYLiveSession *)session debugInfo:(nullable ADYLiveDebug *)debugInfo;
/** callback socket errorcode */
- (void)liveSession:(nullable ADYLiveSession *)session errorCode:(ADYLiveSocketErrorCode)errorCode;

@end

@class ADYLiveStreamInfo;

@interface ADYLiveSession : NSObject

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================
/** The delegate of the capture. captureData callback */
@property (nullable, nonatomic, weak) id<ADYLiveSessionDelegate> delegate;

/** The running control start capture or stop capture
 * 音视频采集运行状态
 */
@property (nonatomic, assign) BOOL running;

/** The preView will show OpenGL ES view*/
@property (nonatomic, strong, null_resettable) UIView *preView;

/** 解码播放视图 */
@property (nonatomic, strong) AVCaptureVideoPreviewLayer * _Nullable recordLayer;
/** 摄像头方向设置*/
/** The captureDevicePosition control camraPosition ,default front*/
@property (nonatomic, assign) AVCaptureDevicePosition captureDevicePosition;

/** 美颜设置*/
/** The beautyFace control capture shader filter empty or beautiy */
@property (nonatomic, assign) BOOL beautyFace;

/** The beautyLevel control beautyFace Level. Default is 0.5, between 0.0 ~ 1.0 */
@property (nonatomic, assign) CGFloat beautyLevel;

/** The brightLevel control brightness Level, Default is 0.5, between 0.0 ~ 1.0 */
@property (nonatomic, assign) CGFloat brightLevel;

/**
 * 控制摄像头缩放比例默认为1.0，介于1.0~3.0之间
 * The torch control camera zoom scale default 1.0, between 1.0 ~ 3.0
 */
@property (nonatomic, assign) CGFloat zoomScale;

/**
 * 色调强度
 * 控制色调强度，默认为0.5，介于0.0~1.0之间
 */
@property (nonatomic, assign) CGFloat toneLevel;

/**
 * torch 控制捕捉闪光灯打开或关闭
 * The torch control capture flash is on or off
 */
@property (nonatomic, assign) BOOL torch;

/**
 * 前后摄像头的镜像控制打开或关闭
 * The mirror control mirror of front camera is on or off
 *
 */
@property (nonatomic, assign) BOOL mirror;

/**
 * muted控件回调audiodata，muted将memset设置为0。
 * The muted control callbackAudioData,muted will memset 0.
 */
@property (nonatomic, assign) BOOL muted;

/**
 * 垫片推流 是否开启垫片推流 默认为False 此设置控制 videoConfig - > isSendCloverImage 开启或关闭
 * 垫片图片请在 videoConfig 进行设置 cloverImage 若不设置即截取第一帧为垫片图片进行推流
 */
@property (nonatomic, assign) BOOL gasket;

/**
 * 自适应比特率控制自动调整比特率。默认为否
 * The adaptiveBitrate control auto adjust bitrate. Default is NO
 *
 */
@property (nonatomic, assign) BOOL adaptiveBitrate;

/** The stream control upload and package*/
@property (nullable, nonatomic, strong, readonly) ADYLiveStreamInfo *streamInfo;

/** The status of the stream .*/
@property (nonatomic, assign, readonly) ADYLiveState state;

/** The captureType control inner or outer audio and video .*/
@property (nonatomic, assign, readonly) ADYLiveCaptureTypeMask captureType;

/** The showDebugInfo control streamInfo and uploadInfo(1s)  (showDebugInfo控制streamInfo和uploadInfo（1s）)*.*/
@property (nonatomic, assign) BOOL showDebugInfo;

/** The reconnectInterval control reconnect timeInterval(重连间隔) *.*/
@property (nonatomic, assign) NSUInteger reconnectInterval;

/** The reconnectCount control reconnect count (重连次数) *.*/
@property (nonatomic, assign) NSUInteger reconnectCount;

/***
 * The warterMarkView control whether the watermark is displayed or not ,if set ni,will remove watermark,otherwise add.
 * set alpha represent mix.Position relative to outVideoSize.
 * warterMarkView控制是否显示水印，如果设置为ni，则删除水印，否则添加水印。
 * 设置alpha表示混合。相对于outVideoSize的位置。
 *.*/
@property (nonatomic, strong, nullable) UIView *warterMarkView;

/* The currentImage is videoCapture shot */
/* 当前图像为视频捕获快照 */
@property (nonatomic, strong,readonly ) UIImage * _Nullable currentImage;


/* The saveLocalVideo is save the local video */
/* saveLocalVideo 判断是否保存本地视频 */
@property (nonatomic, assign, readonly) BOOL saveLocalVideo;

/* The saveLocalVideoPath is save the local video  path */
/** saveLocalVideoPath是保存本地视频路径 */
@property (nonatomic, strong, nullable) NSURL *saveLocalVideoPath;


#pragma mark - Initializer
///=============================================================================
/// @name Initializer
///=============================================================================
- (nonnull instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (nonnull instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 * The designated initializer. Multiple instances with the same configuration will make the capture unstable.
 * 指定的初始值设定项。具有相同配置的多个实例将使捕获不稳定。
 */
- (nullable instancetype)initWithAudioConfiguration:(nullable ADYLiveAudioConfiguration *)audioConfiguration videoConfiguration:(nullable ADYLiveVideoConfiguration *)videoConfiguration onView:(UIView *_Nullable)view;

/**
 * The designated initializer. Multiple instances with the same configuration will make the capture unstable.
 * 指定的初始值设定项。具有相同配置的多个实例将使捕获不稳定。
 */
- (nullable instancetype)initWithAudioConfiguration:(nullable ADYLiveAudioConfiguration *)audioConfiguration videoConfiguration:(nullable ADYLiveVideoConfiguration *)videoConfiguration captureType:(ADYLiveCaptureTypeMask)captureType  onView:(UIView *_Nullable)view NS_DESIGNATED_INITIALIZER;
/**
 更新配置信息
 */
-(void)UpDataConfig;

/** The start stream .*/
- (void)startLive:(nonnull ADYLiveStreamInfo *)streamInfo isEnc:(BOOL) isEnc;

/** The stop stream .*/
- (void)stopLive;




///**
// * ------------------------------------以下是原相机录制采集方法-----------------------------------------
// */
///**视频分辨率*/
//-(void) setCameraResolutionByActiveFormatWithHeight:(int)height;
///**帧率设置*/
//-(void) setCameraForHFRWithFrameRate:(int)frameRate;
///**闪光灯*/
//-(void) tourchState:(BOOL)isOpen;
///**画布拉伸模式*/
//-(void) setVideoGravity:(AVLayerVideoGravity _Nullable )videoGravity;
///**曝光*/
//-(void) exposureNewValue:(CGFloat)newValue;
///**白平衡*/
//-(void) setWhiteBlanceValue:(CGFloat)newValue;
///**色彩*/
//-(void) setWhiteBlanceValueByTint:(CGFloat)newValue;
///**点击聚焦*/
//-(void) setFocusPoint:(CGPoint)point;
///**获取帧率*/
//-(NSInteger)captureVideoFPS;
///**获取当前分辨率*/
//-(NSString *_Nullable) resolution;
///**获取最小曝光度*/
//-(CGFloat)getMinExposureValue;
///**获取最大曝光度*/
//-(CGFloat)getMaxExposureValue;
///** 设备方向调整*/
//- (void) adjustVideoOrientationByScreenOrientation:(UIInterfaceOrientation)orientation;


/**
 * support outer input yuv or rgb video(set ADYLiveCaptureTypeMask) .
 * 支持外部输入yuv或rgb视频（设置ADYLiveCaptureTypeMask）
 */
- (void)pushVideo:(nullable CVPixelBufferRef)pixelBuffer;

/**
 * support outer input pcm audio(set ADYLiveCaptureTypeMask) .
 * 支持外部输入pcm音频（设置ADYLiveCaptureTypeMask）
 */
- (void)pushAudio:(nullable NSData*)audioData;

/**
 * 发送处理后数据流
 */
- (void)pushSendBuffer:(ADYFrame*_Nullable)frame;
/**
 * 录制
 * 开始录制：
 * @param localFileURL 录制路径
 */
- (void)startRecordingToLocalFileURL:(NSURL *_Nullable)localFileURL;

/**
 * 停止录制
 */
- (void)stopRecording;

/**
 * 停止录制回调
 */
- (void)stopRecordingWithCompletionHandler:(void(^_Nullable)(void))completionHandler;

@end

