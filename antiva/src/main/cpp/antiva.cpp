#include <jni.h>
#include <string>
#include "syscalls.h"
#include "cmdline.h"
#include "analysis.h"

using namespace std;

#define SO_APP_LIB "/data/app-lib/"
#define SO_APP_LIB_LEN strlen(SO_APP_LIB)

#define SO_DATA_APP "/data/app/"
#define SO_DATA_APP_LEN strlen(SO_DATA_APP)

#define SO_DATA_DATA "/data/data/"
#define SO_DATA_DATA_LEN strlen(SO_DATA_DATA)
extern "C" {

ALWAYS_INLINE int detectFakeUid() {
    //正常情况下一个uid仅对应一个应用进程
    int count = analysis::countPathFromUid();
    return count;
}

ALWAYS_INLINE int detectFakePath() {
    vector<string> v;
    int pid = Sys::wrap_getpid();
    char *process = cmdline::getProcessName(); //获取当前app进程名
    if (process == NULL) {
        return 0;
    }
    size_t len = strlen(process);
    int i = 0;
    //分析当前maps下的自身so的路径，全部放到vector中
    analysis::findInMaps(pid, "libantiva.so", v);
    for (auto itt = v.begin(); itt != v.end(); itt++) {
        string path = *itt;
        const char *lib = path.c_str();
        if (strstr(lib, process) != NULL) {
            //正常情况下，so的加载路径只会是如下几种模式，并且包名一定是原始app的包名
            //va执行时会将当前app的库文件拷贝到自己的私有目录下，执行重定向后进行加载，所以当前执行的路径为va虚拟机的路径
            if (Strings::startsWith(lib, SO_APP_LIB)) {
                if (strncmp(lib + SO_APP_LIB_LEN, process, len)) {
                    i++;
                }
            } else if (Strings::startsWith(lib, SO_DATA_APP)) {
                if (strncmp(lib + SO_DATA_APP_LEN, process, len)) {
                    i++;
                }
            } else if (Strings::startsWith(lib, SO_DATA_DATA)) {
                if (strncmp(lib + SO_DATA_DATA_LEN, process, len)) {
                    i++;
                }
            }
        }
    }
    free(process);
    v.clear();
    vector<string>(v).swap(v);
    return i;
}

JNIEXPORT jint JNICALL
Java_com_ysrc_antiva_AntiVaNative_isRunInVa(JNIEnv *env, jclass type) {
    return detectFakePath() + detectFakeUid();
}
}