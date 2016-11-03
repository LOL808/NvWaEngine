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
#include <string>

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

NWData* FileHelper::getData(NW_FILETYPE type, const char* filename, bool isText) {

    char* fullpath;
    fullpath = appendPath(_bundlePath, filename);
    size_t size=0;
    unsigned char* data = NWFilePorting_getData(fullpath, isText, &size);


    if (data) {
        NWData* nwData = new NWData(data, size);
        if (isText && 239==data[0] && 187==data[1] && 191 ==data[2]) {
            nwData->setBOM(true);
        }
        return nwData;
    }
    return nullptr;
}

char* FileHelper::appendPath(const char *former,const char *later) {
    size_t lenF = strlen(former);
    size_t lenL = strlen(later);
    char* ret = (char*)calloc(sizeof(char), lenF+lenL+2);
    strncpy(ret, former, lenF);
    ret[lenF] = '/';
    strncpy(ret+lenF+1, later, lenL);
    return ret;
}


