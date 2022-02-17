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


static void io_action(struct ev_loop *main_loop,ev_io*io_w,int e){
    //LOGE("io_action");
}

static void timer_action(struct ev_loop *main_loop,ev_timer*time_w,int e){
     LOGE("timer_action");
}

JNIEXPORT jstring JNICALL Java_com_guanren_libevjnibuilddemo_EvUtils_init
        (JNIEnv *env, jclass cls) {
    // new 一个字符串，返回Hello World

    const char * version = event_get_version();
    LOGE("version:%s",version);

    struct ev_loop *loop = EV_DEFAULT;
    /**
    * 监听socket的读事件,socket 这里假设设置为0'
    * 所监听的事件，包括EV_READ, EV_WRITE 或 EV_READ | EV_WRITE
    */
    ev_io io_watcher;
    ev_io_init(&io_watcher,io_action,0,EV_READ);
    ev_io_start(loop,&io_watcher);

    /**
    * ev_tstamp at; 定时器时间，单位为s
    * ev_tstamp repeat; 是否重复
    */
    ev_timer timer_watcher;
    ev_timer_init(&timer_watcher,timer_action,1.5,1);
    ev_timer_start(loop,&timer_watcher);
    //ev_timer_stop(loop,&timer_watcher);

    ev_run(loop,0);

    return (*env) -> NewStringUTF(env,"Hello World");
}