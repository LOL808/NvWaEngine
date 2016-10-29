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

const Vertex DVertices[] = {
    {{1, -1, 0}, {1, 0, 0, 1}},
    {{1, 1, 0}, {0, 1, 0, 1}},
    {{-1, 1, 0}, {0, 0, 1, 1}},
    {{-1, -1, 3}, {0, 0, 0, 1}}
};

const GLushort DIndices[] = {
    0,1,2,2,3,0
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
//    _verties[0] = {1,-1,0};
//    _verties[1] = {1,-1,0};
//    _verties[2] = {-1,1,0};
//    _verties[3] = {1,1,0};
//
//    _colors[0] = _colors[1] = _colors[2] = _colors[3] = color;
////    for (int i=0; i<4; i++) {
//        _colors[i] = color;
//    }

    return true;
}

void TestDrawNode::draw() {
//    glViewport(0, 0, 100, 100);
//    NWMat4* projection = (NWMat4*)malloc(sizeof(NWMat4));
//    NWMath_OrthographicProjection(projection, -1.0f, 1.0f, -1.0f, 1.0f, -3.0f, 10.0f);
    GLuint vb;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(DVertices), DVertices, GL_STATIC_DRAW);


//    glBufferData(GL_ARRAY_BUFFER, 0, sizeof(_verties), GLenum usage)
//    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_verties), _verties);

//    glBufferSubData(GL_ARRAY_BUFFER, sizeof(_verties), sizeof(_colors), _colors);

    GLuint ib;
    glGenBuffers(1, &ib);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(DIndices), DIndices, GL_STATIC_DRAW);

//    GLuint cb;
//    glGenBuffers(1, &cb);
//    glBindBuffer(GL_ARRAY_BUFFER, cb);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(_colors), _colors, GL_STATIC_DRAW);

//    glUniformMatrix4fv(_glProgarm->getProjectionSlot(), 1, 0, projection->mat);

    glVertexAttribPointer(_glProgarm->getPositionSlot(), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(_glProgarm->getColorSlot(), 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float)*3));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0);
}

void TestDrawNode::testFoo(float x, float y, float w, float h) {
//    /  glViewport(x, y, w, h);
}

TestDrawNode::TestDrawNode() {

}

TestDrawNode::~TestDrawNode() {
    
}
