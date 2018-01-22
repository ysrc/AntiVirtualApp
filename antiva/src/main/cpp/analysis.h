//
// Created by qtfreet00 on 2018/1/22.
//

#ifndef VADETECT_ANALYSIS_H
#define VADETECT_ANALYSIS_H

#include "log.h"
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include "stringUtils.h"
using namespace std;

class analysis {
public:
    static void findInMaps(int, const char *filter, vector<string> &result);
};


#endif //VADETECT_ANALYSIS_H
