//
//  Module:   ADYAudioFrame   @ ADYLiveSDK
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



#if __has_include(<ADYLiveSDK/ADYLiveSDK.h>)
#import <ADYLiveSDK/ADYFrame.h>
#else
#import "ADYFrame.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ADYAudioFrame : ADYFrame

/**
 *  flv打包中aac的header
 */
@property (nonatomic, strong) NSData *audioInfo;


/**
 *  音频的平均码率
 */
@property (nonatomic) NSInteger currentAudioBitRate;
@end

NS_ASSUME_NONNULL_END
