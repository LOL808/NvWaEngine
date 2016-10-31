//
//  TestDrawNode.cpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "TestDrawNode.h"
#include "NWMatMath.h"
#include "NWMath.h"
#include "../Core/Director.h"

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

TestDrawNode* TestDrawNode::createWithColorAndSize(const NWFloatColor& color,const NWSize& size) {
    TestDrawNode* pRet = new TestDrawNode(color, size);
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

//    _verties = {
//        {{1, -1, 0}, {1, 0, 0, 1}},
//        {{1, 1, 0}, {0, 1, 0, 1}},
//        {{-1, 1, 0}, {0, 0, 1, 1}},
//        {{-1, -1, 0}, {0, 0, 0, 1}}
//    }
//    _verties[0].position = {0,100,0};
//    _verties[1].position = {0, 0,0};
//    _verties[2].position = {100,100,0};
//    _verties[3].position = {100,0,0};

//    _verties[0].color = _verties[1].color = _verties[2].color = _verties[3].color = color;

//    _verties = {NWVector3{1,-1,0},{1,1,0},{-1,1,0},{-1,-1,0}};
//    _verties[0] = {1,-1,0};
//    _verties[1] = {1,1,0};
//    _verties[2] = {-1,1,0};
//    _verties[3] = {-1,-1,0};
//
//    _colors[0] = _colors[1] = _colors[2] = _colors[3] = color;
////    for (int i=0; i<4; i++) {
//        _colors[i] = color;
////    }
//    GLuint vertexBuffer;
    glGenBuffers(1, &_vertexBuffer);


    return true;
}

void TestDrawNode::draw() {

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    if (_isVertextDirty) {
         glBufferData(GL_ARRAY_BUFFER, sizeof(_verties), _verties, GL_DYNAMIC_DRAW);
        _isVertextDirty = false;
    }


    glUniformMatrix4fv(_glProgarm->getModelViewSlot(), 1, GL_FALSE, _modelView.mat);
    glUniformMatrix4fv(_glProgarm->getProjectionSlot(), 1, GL_FALSE, Director::getInstance()->getProjectionMatrix().mat);
    glVertexAttribPointer(_glProgarm->getPositionSlot(), 3, GL_FLOAT, GL_FALSE,
                          sizeof(NWBaiscVertex), 0);
    glVertexAttribPointer(_glProgarm->getColorSlot(), 4, GL_FLOAT, GL_FALSE,
                          sizeof(NWBaiscVertex), (GLvoid*) (sizeof(float) * 3));

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void TestDrawNode::testFoo(float x, float y, float w, float h) {
//    /  glViewport(x, y, w, h);
//    _modelView->mat[12]=x;
//    _modelView->mat[13]=y;

}


TestDrawNode::TestDrawNode() {
//    _modelView = new NWMat4;
//    NWMath_modelView(_modelView, nullptr, nullptr, nullptr);
}

TestDrawNode::TestDrawNode(const NWFloatColor& color, const NWSize& size):Node() {
//    _modelView = new NWMat4;
//    NWMath_modelView(_modelView, nullptr, nullptr, nullptr);

    _verties[0].position = {-size.width/2,size.height/2,0};
    _verties[1].position = {-size.width/2,-size.height/2,0};
    _verties[2].position = {size.width/2,size.height/2,0};
    _verties[3].position = {size.width/2,-size.height/2,0};

    _verties[0].color = _verties[1].color = _verties[2].color = _verties[3].color = color;

}

TestDrawNode::~TestDrawNode() {
    
}
