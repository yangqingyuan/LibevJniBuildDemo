//
// Created by 杨青远 on 2/17/22.
//

#include<jni.h>

#ifndef _Hncluded_com_guanren_libevjnibuilddemo_EnvUtils
#define _Hncluded_com_guanren_libevjnibuilddemo_EnvUtils

#ifdef __cplusplus

extern "C"{
#endif

JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_initEv
        (JNIEnv *env, jclass);

JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_testTimerAgain
        (JNIEnv *env, jclass cls,jint sec);

#ifdef __cplusplus
}
#endif
#endif
