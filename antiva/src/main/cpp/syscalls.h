//
// Created by qtfreet00 on 2018/1/22.
//

#ifndef VADETECT_SVC_H
#define VADETECT_SVC_H


#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

class Sys {

public:
    static pid_t wrap_getpid(void);

    static int wrap_open(const char *path, int flags);

    static int wrap_close(int fd);

    static ssize_t wrap_read(int fd, void *buf, size_t count);

    static uid_t wrap_getuid(void);

};


#endif //VADETECT_SVC_H
