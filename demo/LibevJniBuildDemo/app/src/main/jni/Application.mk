APP_STL := stlport_static
APP_CPPFLAGS := -frtti -fexceptions -std=c++11
APP_ABI := arm64-v8a armeabi-v7a
#注意APP_PLATFORM版本低于21编译armeabi-v7a的时候会报错error: undefined reference to 'inotify_init1'
APP_PLATFORM := android-21
LOCAL_ARM_NEON := true