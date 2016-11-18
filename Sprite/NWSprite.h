//
//  NWSprite.hpp
//  NvWaEngine
//
//  Created by /help on 11/5/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_SPRITE_NWSPRITE_H_
#define _NVWA_ENGINE_SPRITE_NWSPRITE_H_


#include "../Nodes/Node.h"
#include <string>

class NWSpriteFrame;


class NWSprite : public Node{
public:
    static NWSprite* createWithSpriteFrame(const NWSpriteFrame* spriteFrame);
    static NWSprite* createWithName(const std::string name);

//protected:

    void draw();

private:
    NWSprite(const NWSpriteFrame* spriteFrame);
    ~NWSprite();


    NWSpriteFrame* _spriteFrame;


};

#endif /* NWSprite_hpp */
