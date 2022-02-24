LOCAL_PATH := $(call my-dir)


##############libavformat##############
include $(CLEAR_VARS)
LOCAL_MODULE := libevent
LOCAL_SRC_FILES := $(LOCAL_PATH)/lib/libevent.a
include $(PREBUILT_STATIC_LIBRARY)

##############libavformat##############
include $(CLEAR_VARS)
LOCAL_MODULE := libevent_core
LOCAL_SRC_FILES := $(LOCAL_PATH)/lib/libevent_core.a
include $(PREBUILT_STATIC_LIBRARY)

##############libavformat##############
include $(CLEAR_VARS)
LOCAL_MODULE := libevent_extra
LOCAL_SRC_FILES := $(LOCAL_PATH)/lib/libevent_extra.a
include $(PREBUILT_STATIC_LIBRARY)

##############libavformat##############
include $(CLEAR_VARS)
LOCAL_MODULE := libevent_pthreads
LOCAL_SRC_FILES := $(LOCAL_PATH)/lib/libevent_pthreads.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libev


LOCAL_SRC_FILES := $(LOCAL_PATH)/jniTest.c \


#头文件
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/event \
                    $(LOCAL_PATH)/include/common \
                    $(LOCAL_PATH) \


LOCAL_LDLIBS += -llog
LOCAL_LDLIBS +=-lm

LOCAL_STATIC_LIBRARIES := \
    libevent_extra libevent libevent_extra libevent_pthreads

include $(BUILD_SHARED_LIBRARY)
include $(all-subdir-makefiles)