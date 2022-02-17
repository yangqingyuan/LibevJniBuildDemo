//
// Created by 杨青远 on 2/17/22.
//

#include "jniTest.h"
#include "config.h"
#include "event.h"
#include "ev.h"
#include "log.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct event_base *eb;

JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_init
        (JNIEnv *env, jclass cls) {
    // new 一个字符串，返回Hello World

    const char * version = event_get_version();
    LOGE("version:%s",version);
    //event_new(eb, -1, 0, xqc_client_engine_callback, null);
    return (*env) -> NewStringUTF(env,"Hello World");
}