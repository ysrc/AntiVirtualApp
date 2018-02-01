//
// Created by qtfreet00 on 2018/1/22.
//

#ifndef VADETECT_SVC_H
#define VADETECT_SVC_H


#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <jni.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <android/log.h>
#include <dlfcn.h>
#include <stddef.h>
#include <fcntl.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <jni.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <android/log.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class Syscalls {

public:
    static int _gettimeofday(struct timeval *tv, struct timezone *tz);

    static int _kill(pid_t pid, int signal);

    static pid_t _getpid(void);

    static uid_t _getuid(void);

    static __noreturn void _exit(int i);

    static int _faccessat(int dirfd, const char *pathname, int mode, int flags);

    static int _access(const char *file, int mode);

    static int _open(const char *path, int flags);

    static int _close(int fd);

    static ssize_t _read(int __fd, void *__buf, size_t __count);

    static int _openat(int __dir_fd, const char *__path, int __flags);
};


#endif //VADETECT_SVC_H
