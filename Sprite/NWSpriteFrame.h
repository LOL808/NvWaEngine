//
//  NWSpriteFrame.hpp
//  NvWaEngine
//
//  Created by /help on 11/4/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_SPRITE_NWSPRITEFRAME_H_
#define _NVWA_ENGINE_SPRITE_NWSPRITEFRAME_H_

#include "../Math/NWMath.h"
#include <string>
using namespace std;

class NWSprite;
class TestDrawNode;

class NWSpriteFrame{
    friend class NWSprite;
    friend class TestDrawNode;
public:
    static NWSpriteFrame* create(const char* filename);

protected:
    bool init(const char* filename);

private:
    NWSpriteFrame(const char* filename);
    ~NWSpriteFrame();
private:

    NWRect _frame;
    NWSize _size;
    GLint  _texture;
    const  string _spriteFrameName;
};

#endif /* NWSpriteFrame_hpp */
