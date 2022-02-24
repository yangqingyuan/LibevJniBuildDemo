//
// Created by 杨青远 on 2/17/22.
//

#include "jniTest.h"


#include "event2/event.h"


#include "log.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <mm_malloc.h>

struct event_base *eb;
struct event   *ev_engine;

static inline uint64_t now()
{
    /* get microsecond unit time */
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t ul = tv.tv_sec * (uint64_t)1000000 + tv.tv_usec;
    return  ul;
}

 void callback(int severity, const char *msg){
    LOGE("callback  severity:%d, msg:%s",severity,msg);
 }
static void
xqc_client_engine_callback(int fd, short what, void *arg)
{
    LOGE("timer wakeup now:%lu", now());
}

/**
* 直接使用ev.h的接口
*/
JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_initEv
        (JNIEnv *env, jclass cls) {
    // new 一个字符串，返回Hello World
    eb = event_base_new();
    event_set_log_callback(callback);
    ev_engine = event_new(eb, -1, 0, xqc_client_engine_callback, eb);
    //event_base_set(eb,ev_engine);
    event_add(ev_engine,NULL);
    LOGE("event ev_run start A");
    event_base_loop(eb,EVLOOP_NO_EXIT_ON_EMPTY);
    LOGE("event ev_run end B");
    return (*env) -> NewStringUTF(env,"Hello World");
}

/**
*
*/
JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_testTimerAgain
        (JNIEnv *env, jclass cls,jint sec) {
    struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 1000;
        event_add(ev_engine, &tv);
        LOGE("event_add A");
    return (*env) -> NewStringUTF(env,"Hello World");
 }