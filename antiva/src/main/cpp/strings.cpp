//
// Created by qtfreet00 on 2018/1/22.
//

#include <string.h>
#include "strings.h"

int Strings::endsWith(const char *str, const char *suffix) {
    if (!str || !suffix)
        return 0;
    size_t lenA = strlen(str);
    size_t lenB = strlen(suffix);
    if (lenB > lenA)
        return 0;
    return strncmp(str + lenA - lenB, suffix, lenB) == 0;
}

int Strings::startsWith(const char *str, const char *suffix) {
    if (!str || !suffix)
        return 0;
    size_t lenA = strlen(str),
            lenB = strlen(suffix);
    if (lenB > lenA)
        return 0;
    return strncmp(str, suffix, lenB) == 0;
}