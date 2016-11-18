//
//  TestDrawNode.hpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef TestDrawNode_hpp
#define TestDrawNode_hpp

#include "Node.h"
#include "../Math/NWTypes.h"
#include "../Texture/NWTexture.h"
#include "../Sprite/NWSpriteFrame.h"




class TestDrawNode : public Node {

public:
    static TestDrawNode* createWithSpriteFrame(const NWSpriteFrame* spriteFrame);
    static TestDrawNode* createWithColorAndSize(const NWFloatColor& color,const NWSize& size);
    static TestDrawNode* createWithSprite(const char* filename);

    TestDrawNode();
    TestDrawNode(int count);
    TestDrawNode(const NWFloatColor& color, const NWSize& size);
    virtual ~TestDrawNode();


    void draw();

protected:
    bool initWithSpriteFrame(const NWSpriteFrame* spriteFrame);
    bool initWithColor(const NWFloatColor& color);
    bool initWithFile(const char* filename);

private:

    NWSpriteFrame* _spriteFrame;
    NWTexture       *m_texture;
    NWTexVertex   testVerties[3];

};

#endif /* TestDrawNode_hpp */
