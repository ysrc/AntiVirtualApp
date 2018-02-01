//
// Created by qtfreet00 on 2018/2/1.
//


#include "utils.h"


jobject utils::getGlobalContext(JNIEnv *env) {
    jobject context = NULL;
    //获取Activity Thread的实例对象
    jclass activityThread = env->FindClass("android/app/ActivityThread");
    if (activityThread != NULL) {
        jmethodID currentApplication = env->GetStaticMethodID(activityThread,
                                                              "currentApplication",
                                                              "()Landroid/app/Application;");
        if (currentApplication != NULL) {
            context = env->CallStaticObjectMethod(activityThread, currentApplication);
        }
        env->DeleteLocalRef(activityThread);
    }
    return context;
}

jstring utils::getPackageName(JNIEnv *env, jobject context) {
    jstring pkg_str = NULL;
    if (context != NULL) {
        jclass ctx_clz = env->GetObjectClass(context);
        if (ctx_clz != NULL) {
            jmethodID pkg_method = env->GetMethodID(ctx_clz,
                                                    "getPackageName",
                                                    "()Ljava/lang/String;");
            if (pkg_method != NULL) {
                pkg_str = (jstring) env->CallObjectMethod(context,
                                                          pkg_method);
            }
            env->DeleteLocalRef(ctx_clz);
        }
    }
    return pkg_str;
}