//
//  Module:   ADYVideoFrame   @ ADYLiveSDK
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

@interface ADYVideoFrame : ADYFrame
/**
 *  是否关键帧
 */
@property (nonatomic, assign) BOOL isKeyFrame;
/**
 * 是否发送SEI补充关键信息
 */
@property (nonatomic, assign) BOOL isSendSEI;
/**
 *  视频的sps信息
 */
@property (nonatomic, strong) NSData *sps;
/**
 *  视频的pps信息
 */
@property (nonatomic, strong) NSData *pps;

/**
 *  视频的平均码率 单位 bps
 */
@property (nonatomic) NSInteger currentVideoBitRate;


@end

NS_ASSUME_NONNULL_END
