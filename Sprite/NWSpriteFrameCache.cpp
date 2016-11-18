//
//  NWSpriteFrameCache.cpp
//  NvWaEngine
//
//  Created by /help on 11/4/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWSpriteFrameCache.h"

NWSpriteFrameCache* NWSpriteFrameCache::_instance = nullptr;

NWSpriteFrameCache* NWSpriteFrameCache::getInstance() {
    if (!_instance) {
        _instance = new NWSpriteFrameCache();
    }
    return _instance;
}

NWSpriteFrameCache::NWSpriteFrameCache() {
    
}

void NWSpriteFrameCache::addSpriteFrame(const std::string frameName, NWSpriteFrame *frame) {
    _map.insert(make_pair(frameName, frame));
}

NWSpriteFrame* NWSpriteFrameCache::getSpriteFrame(const std::string frameName) {
    map<std::string, NWSpriteFrame*>::iterator it= _map.begin();
    it = _map.find(frameName);
    if (it==_map.end())
        return nullptr;
    return it->second;
}
