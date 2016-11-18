//
//  NWSpriteFrameCache.hpp
//  NvWaEngine
//
//  Created by /help on 11/4/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_SPRITE_SPRITEFRAMECACHE_
#define _NVWA_ENGINE_SPRITE_SPRITEFRAMECACHE_

#include <NWTypes.h>
#include <map>
#include "NWSpriteFrame.h"

class NWSpriteFrameCache {
public:
    static NWSpriteFrameCache* getInstance();
    
    void addSpriteFrame(const std::string frameName, NWSpriteFrame* frame);
    NWSpriteFrame* getSpriteFrame(const std::string frameName);
    
private:
    NWSpriteFrameCache();

private:
    static NWSpriteFrameCache* _instance;
    
    std::map<std::string,NWSpriteFrame*> _map;
};

#endif /* NWSpriteFrameCache_hpp */
