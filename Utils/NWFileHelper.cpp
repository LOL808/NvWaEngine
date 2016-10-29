//
//  FileHelper.cpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWFileHelper.h"
#include "../Porting/NWFilePorting.h"

FileHelper* FileHelper::_instance = nullptr;


FileHelper* FileHelper::getInstance() {
    if (!_instance) {
        _instance = new FileHelper;
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