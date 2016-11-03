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
#include "../Utils/NWFileHelper.h"



TestDrawNode* TestDrawNode::createWithSprite(const char *filename) {
    return nullptr;
}


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


TestDrawNode::TestDrawNode() {
}

TestDrawNode::TestDrawNode(const NWFloatColor& color, const NWSize& size):Node() {

    _verties[0].position = {-size.width/2,size.height/2,0};
    _verties[1].position = {-size.width/2,-size.height/2,0};
    _verties[2].position = {size.width/2,size.height/2,0};
    _verties[3].position = {size.width/2,-size.height/2,0};

    _verties[0].color = _verties[1].color = _verties[2].color = _verties[3].color = color;

}

TestDrawNode::~TestDrawNode() {
    
}
