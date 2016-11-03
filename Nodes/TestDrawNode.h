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


class TestDrawNode : public Node {

public:
    static TestDrawNode* createWithColorAndSize(const NWFloatColor& color,const NWSize& size);
    static TestDrawNode* createWithSprite(const char* filename);

    TestDrawNode();
    TestDrawNode(const NWFloatColor& color, const NWSize& size);
    virtual ~TestDrawNode();


    void draw();

protected:
    bool initWithColor(const NWFloatColor& color);

private:


};

#endif /* TestDrawNode_hpp */
