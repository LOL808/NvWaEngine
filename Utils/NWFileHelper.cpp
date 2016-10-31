//
//  FileHelper.cpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWFileHelper.h"
#include "../Porting/NWFilePorting.h"
#include <string.h>
#include <stdlib.h>

FileHelper* FileHelper::_instance = nullptr;


FileHelper* FileHelper::getInstance() {
    if (!_instance) {
        _instance = new FileHelper();
    }
    return _instance;
}

FileHelper::FileHelper():_bundlePath(nullptr),_resPath(nullptr) {
    _bundlePath = NWFilePorting_getBundlePath();
    
}

FileHelper::~FileHelper() {
    if (_resPath) {
        delete _resPath;
    }
    if (_bundlePath) {
        delete _bundlePath;
    }
}

char* FileHelper::appendPath(char *former, char *later) {
    size_t lenF = strlen(former);
    size_t lenL = strlen(later);
    char* ret = (char*)calloc(sizeof(char), lenF+lenL+2);
    strncpy(ret, former, lenF);
    ret[lenF] = '/';
    strncpy(ret+lenL+1, later, lenF);
    return ret;
}
