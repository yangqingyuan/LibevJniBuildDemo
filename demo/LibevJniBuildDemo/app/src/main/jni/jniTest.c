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
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <mm_malloc.h>

struct event *ev;

ev_io io_watcher;
ev_timer timer_watcher;
struct ev_loop *loop;

static void io_action(struct ev_loop *main_loop,ev_io*io_w,int e){
    //LOGE("io_action");
}

static void timer_action(struct ev_loop *main_loop,ev_timer*time_w,int e){
     LOGE("timer_action %f, %d",time_w->repeat,e);
}

static void callback(int fd, short what, void *arg)
{
    LOGE("callback");
}

/**
* 直接使用ev.h的接口
*/
JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_initEv
        (JNIEnv *env, jclass cls) {
    // new 一个字符串，返回Hello World

    const char * version = event_get_version();
    LOGE("ev version:%s",version);

    loop = EV_DEFAULT;

    /**
    * 监听socket的读事件,socket 这里假设设置为0'
    * 所监听的事件，包括EV_READ, EV_WRITE 或 EV_READ | EV_WRITE
    */
    ev_io_init(&io_watcher,io_action,0,EV_READ);
    ev_io_start(loop,&io_watcher);

    /**
    * ev_tstamp at; 定时器时间，单位为s
    * ev_tstamp repeat; 是否重复
    */
    ev_timer_init(&timer_watcher,timer_action,-1,0);
    ev_timer_start(loop,&timer_watcher);
    //ev_timer_stop(loop,&timer_watcher);

    ev_run(loop,0);//阻塞
    //ev_break(loop,EV_NOEXCEPT);
    LOGE("event ev_run end");
    return (*env) -> NewStringUTF(env,"Hello World");
}

/**
*
*/
JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_testTimerAgain
        (JNIEnv *env, jclass cls,jint sec) {
    timer_watcher.repeat = sec;//单位秒
    ev_timer_again (loop, &timer_watcher);//重新设置重复时间，每次调用会覆盖之前的时间，时间开始时间为当前时间
    LOGE("event ev_run repeat:%f",timer_watcher.repeat);
    return (*env) -> NewStringUTF(env,"Hello World");
 }