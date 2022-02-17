//
//  Rt_log.h
//  RunTopSDK
//
//  Created by 杨青远 on 2017/4/12.
//  Copyright © 2017年 杨青远. All rights reserved.
//

#ifndef Rt_log_h
#define Rt_log_h

#include <stdio.h>

#ifdef ANDROID
#include <jni.h>
#include <android/log.h>

#define TAG "xquic_log"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)

#endif
#endif /* Rt_log_h */
