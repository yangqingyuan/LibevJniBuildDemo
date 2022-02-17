LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := libev

#源文件
#MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/src/*.c)
#MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/*.c)
#LOCAL_SRC_FILES := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

LOCAL_SRC_FILES := $(LOCAL_PATH)/src/ev.c \
                   $(LOCAL_PATH)/src/event.c \
                   $(LOCAL_PATH)/jniTest.c \
#头文件
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/ev \
                    $(LOCAL_PATH)/include/common \
                    $(LOCAL_PATH) \


LOCAL_LDLIBS += -llog
LOCAL_LDLIBS +=-lm

include $(BUILD_SHARED_LIBRARY)