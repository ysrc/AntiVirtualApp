//
// Created by qtfreet00 on 2018/1/22.
//

#include "syscalls.h"


pid_t Sys::wrap_getpid(void) {
    pid_t pid = (pid_t) syscall(__NR_getpid);
    return pid;
}

int Sys::wrap_open(const char *path, int flags) {
    int ret = (int) syscall(__NR_openat, AT_FDCWD, path, flags);
    return ret;
}

ssize_t Sys::wrap_read(int fd, void *buf, size_t count) {
    ssize_t ret = syscall(__NR_read, fd, buf, count);
    return ret;
}

int Sys::wrap_close(int fd) {
    return (int) syscall(__NR_close, fd);
}

uid_t Sys::wrap_getuid(void) {
    uid_t ret;
#if defined(__arm__)|| defined(__i386__)
    ret = (uid_t) syscall(__NR_getuid32);
#else
    ret = (uid_t) syscall(__NR_getuid);
#endif
    return ret;
}