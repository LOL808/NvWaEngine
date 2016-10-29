//
//  TestDrawNode.cpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "TestDrawNode.h"

typedef struct{
    float Position[3];
    float Color[4];
}Vertex;

const Vertex DVertices[] ={
    {{1, -1, 0}, {1, 0, 0, 1}},
    {{1, 1, 0}, {0, 1, 0, 1}},
    {{-1, 1, 0}, {0, 0, 1, 1}},
    {{-1, -1, 0}, {0, 0, 0, 1}}
};

const GLubyte DIndices[] = {
    0, 1, 2,
    2, 3, 0
};

TestDrawNode* TestDrawNode::createWithColorAndSize(const NWFloatColor& color) {
    TestDrawNode* pRet = new TestDrawNode;
//    if (!initWithColor(color)) {
//        return false;
//    }
    if (pRet&&pRet->initWithColor(color)) {
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return pRet;
//    return pRet;
}


bool TestDrawNode::initWithColor(const NWFloatColor &color) {

//    _verties = {NWVector3{1,-1,0},{1,1,0},{-1,1,0},{-1,-1,0}};
    _verties[0] = {1,-1,0};
    _verties[1] = {1,1,0};
    _verties[2] = {-1,1,0};
    _verties[3] = {-1,-1,0};
//
    _colors[0] = _colors[1] = _colors[2] = _colors[3] = color;
////    for (int i=0; i<4; i++) {
//        _colors[i] = color;
//    }

    return true;
}

void TestDrawNode::draw() {
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(DVertices), DVertices, GL_STATIC_DRAW);

    

    GLuint indexBuffer;
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(DIndices), DIndices, GL_STATIC_DRAW);

    glVertexAttribPointer(_glProgarm->getPositionSlot(), 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), 0);
    glVertexAttribPointer(_glProgarm->getColorSlot(), 4, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (GLvoid*) (sizeof(float) * 3));

    // 3
    glDrawElements(GL_TRIANGLES, sizeof(DIndices)/sizeof(DIndices[0]),
                   GL_UNSIGNED_BYTE, 0);
}

void TestDrawNode::testFoo(float x, float y, float w, float h) {
//    /  glViewport(x, y, w, h);
}

TestDrawNode::TestDrawNode() {

}

TestDrawNode::~TestDrawNode() {
    
}
