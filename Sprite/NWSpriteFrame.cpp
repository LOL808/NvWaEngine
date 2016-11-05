//
//  NWSpriteFrame.cpp
//  NvWaEngine
//
//  Created by /help on 11/4/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWSpriteFrame.h"
#include "../Texture/NWTexture.h"


NWSpriteFrame* NWSpriteFrame::create(const char *filename) {
    NWSpriteFrame* pRet = new NWSpriteFrame(filename);
    if (pRet&&pRet->init(filename)) {
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

NWSpriteFrame::NWSpriteFrame(const char* filename):_frame(NWRectMake(0,0,0,0)),_texture(0),_spriteFrameName(string(filename)) {
    
}

bool NWSpriteFrame::init(const char *filename) {

    NWTexture* tex = NWTexture::createWithFile(filename);
    _frame.size.width  = tex->_width;
    _frame.size.height = tex->_height;
    _size.width  = tex->_width;
    _size.height = tex->_height;
    _texture = tex->_texture;

    return true;
}

NWSpriteFrame::~NWSpriteFrame() {

}

