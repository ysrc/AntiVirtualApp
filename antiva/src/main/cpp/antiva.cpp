#include <jni.h>
#include <string>
#include "svc.h"
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


JNIEXPORT jboolean JNICALL
Java_com_ysrc_antiva_JniHelper_isRunInVa(JNIEnv *env, jclass type) {
    std::vector<string> vector;
    int pid = svc::_getpid();
    char *process = cmdline::getProcessName();
    if (process == NULL) {
        return JNI_FALSE;
    }
    size_t len = strlen(process);
    int i = 0;
    analysis::findInMaps(pid, "libantiva.so", vector);
    for (auto itt = vector.begin(); itt != vector.end(); itt++) {
        string path = *itt;
        const char *lib = path.c_str();
        if (strstr(lib, process) != NULL) {
            if (stringUtils::startsWith(lib, SO_APP_LIB)) {
                if (strncmp(lib + SO_APP_LIB_LEN, process, len)) {
                    i++;
                }
            } else if (stringUtils::startsWith(lib, SO_DATA_APP)) {
                if (strncmp(lib + SO_DATA_APP_LEN, process, len)) {
                    i++;
                }
            } else if (stringUtils::startsWith(lib, SO_DATA_DATA)) {
                if (strncmp(lib + SO_DATA_DATA_LEN, process, len)) {
                    i++;
                }
            }
        }
    }
    free(process);
    return (jboolean) (i > 0);

}

}