//
//  NWTexture.cpp
//  NvWaEngine
//
//  Created by /help on 11/3/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWTexture.h"
#include "../Utils/NWFileHelper.h"


NWTexture* NWTexture::createWithFile(const char *filename) {
    NWTexture* pRet = new NWTexture;
    if (pRet&&pRet->initWithFile(filename)) {
        return pRet;
    }
    delete  pRet;
    pRet = nullptr;
    return nullptr;

}

bool NWTexture::initWithFile(const char *filename) {

    NWData* data = FileHelper::getInstance()->getData(NW_FILETYPE_PNG, filename);

    if (!data) {
        return false;
    }

    


    return true;
}

NWTexture::NWTexture() {

}

NWTexture::~NWTexture() {

}