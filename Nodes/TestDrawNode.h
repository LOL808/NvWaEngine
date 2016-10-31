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

    TestDrawNode();
    TestDrawNode(const NWFloatColor& color, const NWSize& size);
    virtual ~TestDrawNode();

    void testFoo(float x, float y, float w, float h);

    void draw();

protected:
    bool initWithColor(const NWFloatColor& color);

private:
//    NWVector3       _verties[4];
//    NWFloatColor    _colors[4];

    

//    GLuint          _vertexBuffer;

    bool            _isDirty;

};

#endif /* TestDrawNode_hpp */
