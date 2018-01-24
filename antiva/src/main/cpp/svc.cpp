//
// Created by qtfreet00 on 2018/1/22.
//

#include "svc.h"
#include <asm/unistd.h>


int svc::_gettimeofday(struct timeval *tv, struct timezone *tz) {
    int ret = (int) syscall(__NR_gettimeofday, tv, tz);
    return ret;
}

int svc::_kill(pid_t pid, int signal) {
    int ret = (int) syscall(__NR_kill, pid, signal);
    return ret;
}

pid_t svc::_getpid(void) {
    pid_t pid = (pid_t) syscall(__NR_getpid);
    return pid;
}

__noreturn void svc::_exit(int i) {
    syscall(__NR_exit, i);
}

int svc::_faccessat(int dirfd, const char *pathname, int mode, int flags) {
    int ret = (int) syscall(__NR_faccessat, dirfd, pathname, mode, flags);
    return ret;
}

int svc::_open(const char *__path, int __flags) {
    int ret;
#if defined(__aarch64__)
    ret = open(__path, __flags);
#else
    ret = syscall(__NR_open, __path, __flags);
#endif
    return ret;
}

ssize_t svc::_read(int __fd, void *__buf, size_t __count) {
    ssize_t ret = syscall(__NR_read, __fd, __buf, __count);
    return ret;
}

int svc::_access(const char *file, int mode) {
    int ret;
#if defined(__aarch64__)
    ret = access(file, mode);
#else
    ret = syscall(__NR_access, file, mode);
#endif
    return ret;
}

int svc::_close(int fd) {
    return (int) syscall(__NR_close, fd);
}

int svc::_openat(int __dir_fd, const char *__path, int __flags) {
    int ret = (int) syscall(__NR_openat, __dir_fd, __path, __flags);
    return ret;
}
