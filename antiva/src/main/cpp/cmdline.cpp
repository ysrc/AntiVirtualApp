//
// Created by qtfreet00 on 2018/1/22.
//

#include <malloc.h>
#include <string.h>
#include <asm/fcntl.h>
#include <unistd.h>
#include "cmdline.h"
#include "svc.h"

/**
 * 获取当前app进程名称
 * @return
 */
char *cmdline::getProcessName() {
    char *buffer = (char *) malloc(1024);
    memset(buffer, 0, 1024);
    char path_t[256] = {0};
    int pid = svc::_getpid();
    memset(path_t, 0, sizeof(path_t));
    sprintf(path_t, "/proc/%d/cmdline", pid);
    int fd_t = svc::_open(path_t, O_RDONLY);
    if (fd_t > 0) {
        int read_count = (int) svc::_read(fd_t, buffer, 1024);
        close(fd_t);
        if (read_count > 0) {
            return buffer;
        }
    }
    free(buffer);
    return NULL;
}