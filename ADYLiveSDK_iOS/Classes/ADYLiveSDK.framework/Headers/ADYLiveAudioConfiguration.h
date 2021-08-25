//
//  Module:   ADYLiveAudioConfiguration   @ ADYLiveSDK
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

/// 音频码率 (默认96Kbps)
typedef NS_ENUM (NSUInteger, ADYLiveAudioBitRate) {
    /// 32Kbps 音频码率
    ADYLiveAudioBitRate_32Kbps = 32000,
    /// 64Kbps 音频码率
    ADYLiveAudioBitRate_64Kbps = 64000,
    /// 96Kbps 音频码率
    ADYLiveAudioBitRate_96Kbps = 96000,
    /// 128Kbps 音频码率
    ADYLiveAudioBitRate_128Kbps = 128000,
    /// 默认音频码率，默认为 96Kbps
    ADYLiveAudioBitRate_Default = ADYLiveAudioBitRate_96Kbps
};

/// 音频采样率 (默认44.1KHz)
typedef NS_ENUM (NSUInteger, ADYLiveAudioSampleRate){
    /// 16KHz 采样率
    ADYLiveAudioSampleRate_16000Hz = 16000,
    /// 44.1KHz 采样率
    ADYLiveAudioSampleRate_44100Hz = 44100,
    /// 48KHz 采样率
    ADYLiveAudioSampleRate_48000Hz = 48000,
    /// 默认音频采样率，默认为 44.1KHz
    ADYLiveAudioSampleRate_Default = ADYLiveAudioSampleRate_44100Hz
};


@interface ADYLiveAudioConfiguration : NSObject<NSCoding, NSCopying>

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================
/// 声道数目(default 2)
@property (nonatomic, assign) NSUInteger numberOfChannels;
/// 采样率
@property (nonatomic, assign) ADYLiveAudioSampleRate audioSampleRate;
/// 码率
@property (nonatomic, assign) ADYLiveAudioBitRate audioBitrate;
/// flv编码音频头 44100 为0x12 0x10
@property (nonatomic, assign, readonly) char *asc;
/// 缓存区长度
@property (nonatomic, assign,readonly) NSUInteger bufferLength;



/// 自定义音频配置
+ (instancetype)customConfiguration;

 /// 默认音频质量 audio sample rate: 44.1KHz, audio bitrate: 96Kbps 默认双声道
+ (instancetype)ADYLiveAudioQuality_Default;

/// 低音频质量 audio sample rate: 16KHz audio bitrate: numberOfChannels 1 : 32Kbps  2 : 64Kbps
+ (instancetype)ADYLiveAudioQuality_Low:(NSUInteger )numberOfChannels;

/// 中音频质量 audio sample rate: 44.1KHz audio bitrate: 96Kbps 默认双声道
+ (instancetype)ADYLiveAudioQuality_Medium;

/// 高音频质量 audio sample rate: 44.1MHz audio bitrate: 128Kbps 默认双声道
+ (instancetype)ADYLiveAudioQuality_High;

/// 超高音频质量 audio sample rate: 48KHz, audio bitrate: 128Kbps 默认双声道
+ (instancetype)ADYLiveAudioQuality_VeryHigh;



@end
