//
// Created by qtfreet00 on 2018/1/22.
//

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "cmdline.h"
#include "syscalls.h"

/**
 * 获取当前app进程名称
 * @return
 */
char *cmdline::getProcessName() {
    char *buffer = (char *) malloc(256);
    memset(buffer, 0, 256);
    char path[64] = {0};
    int pid = Sys::wrap_getpid();
    sprintf(path, "/proc/%d/cmdline", pid);
    int fd = Sys::wrap_open(path, O_RDONLY);
    if (fd > 0) {
        int read_count = (int) Sys::wrap_read(fd, buffer, 256);
        Sys::wrap_close(fd);
        if (read_count > 0) {
            return buffer;
        }
    }
    free(buffer);
    return NULL;
}