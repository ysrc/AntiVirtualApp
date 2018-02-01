//
// Created by qtfreet00 on 2018/2/1.
//

#ifndef VADETECT_UTILS_H
#define VADETECT_UTILS_H

#include <jni.h>

class utils {

public:
    static jobject getGlobalContext(JNIEnv *env);

    static jstring getPackageName(JNIEnv *env, jobject context);
};


#endif //VADETECT_UTILS_H
