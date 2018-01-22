//
// Created by qtfreet00 on 2018/1/22.
//

#include <string.h>
#include "stringUtils.h"

int stringUtils::endsWith(const char *str, const char *suffix) {
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix > lenstr)
        return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}

int stringUtils::startsWith(const char *str, const char *suffix) {
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str),
            lensuffix = strlen(suffix);
    if (lensuffix > lenstr)
        return 0;
    return strncmp(str, suffix, lensuffix) == 0;
}