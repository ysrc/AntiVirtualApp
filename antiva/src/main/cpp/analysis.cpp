//
// Created by qtfreet00 on 2018/1/22.
//


#include "analysis.h"


void analysis::findInMaps(int pid, const char *filter, vector<string> &result) {
    char data[256];
    char s[64] = {0};
    sprintf(s, "/proc/%d/maps", pid);
    FILE *fd = fopen(s, "r");
    if (fd == NULL) {
        return;
    }
    char path[128] = {0};
    char uid[10] = {0};
    while (fgets(data, 256, fd)) {
        int len = (int) strlen(data);
        if (len <= 0) {
            continue;
        }
        data[--len] = '\0';
        sscanf(data, "%*llx-%*llx %s %*s %*s %*s %s", uid, path);
        if (strcmp(uid, "r-xp") == 0 && stringUtils::endsWith(path, filter)) {
            result.push_back(path);
        }
    }
    fclose(fd);
}