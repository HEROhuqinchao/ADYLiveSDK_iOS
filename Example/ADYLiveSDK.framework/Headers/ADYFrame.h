//
//  Module:   ADYFrame   @ ADYLiveSDK
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

NS_ASSUME_NONNULL_BEGIN

@interface ADYFrame : NSObject
/**
 *  时间戳
 */
@property (nonatomic, assign,) uint64_t timestamp;
/**
 * 计时专用时间戳-- SEI补充信息 -- 帧同步处理
 */
@property (nonatomic, assign,) uint64_t timeStamploc;
/**
 *  音视频数据
 */
@property (nonatomic, strong) NSData *data;
/**
 * 组合后数据--目前适用于SEI信息处理
 */
@property(nonatomic, strong, readonly) NSData *fullData;

///< flv或者rtmp包头
@property (nonatomic, strong) NSData *header;
@end

NS_ASSUME_NONNULL_END
