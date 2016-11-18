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
#include "../Math/NWMath.h"
#include "../Utils/NWMacro.h"



TestDrawNode* TestDrawNode::createWithSpriteFrame(const NWSpriteFrame *spriteFrame) {
    TestDrawNode* pRet = new TestDrawNode;
    if (pRet&&pRet->initWithSpriteFrame(spriteFrame)) {
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}


TestDrawNode* TestDrawNode::createWithSprite(const char *filename) {
    TestDrawNode* pRet = new TestDrawNode;
    if (pRet&&pRet->initWithFile(filename)) {
        return pRet;
    }

    delete pRet;
    pRet = nullptr;
    return nullptr;
}


TestDrawNode* TestDrawNode::createWithColorAndSize(const NWFloatColor& color,const NWSize& size) {
    TestDrawNode* pRet = new TestDrawNode(color, size);
    if (pRet&&pRet->initWithColor(color)) {
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return pRet;
}

bool TestDrawNode::initWithFile(const char *filename) {

    m_texture = NWTexture::createWithFile(filename);
    GLfloat left;
    GLfloat right;
    GLfloat top;
    GLfloat bottom;

    left = 1.0;
    right = 0.0;
    top = 1.0;
    bottom = 0.0;

////  LT
    _verties[0].texcoord.u = 0.0f;
    _verties[0].texcoord.v = 1.0f;
////
//  LB
    _verties[1].texcoord.u = 0.0f;
    _verties[1].texcoord.v = 0.0f;
////
////  RB
    _verties[2].texcoord.u = 1.0f;
    _verties[2].texcoord.v = 1.0f;
////
////  RT
    _verties[3].texcoord.u = 1.0f;
    _verties[3].texcoord.v = 0.0f;

    return true;
}


bool TestDrawNode::initWithColor(const NWFloatColor &color) {

    return true;
}

bool TestDrawNode::initWithSpriteFrame(const NWSpriteFrame *spriteFrame) {

    GLfloat left;
    GLfloat right;
    GLfloat top;
    GLfloat bottom;

    left = 1.0;
    right = 0.0;
    top = 1.0;
    bottom = 0.0;

//    _nodeSize = spriteFrame->_size;
//    _nodeSize = NWSizeMake(50, 50);

    NWFloatColor color = NWFloatColorMake(1.0, 1.0, 1.0, 1.0);
    _verties[0].position = {-_nodeSize.width/2,_nodeSize.height/2,0};
    _verties[1].position = {-_nodeSize.width/2,-_nodeSize.height/2,0};
    _verties[2].position = {_nodeSize.width/2,_nodeSize.height/2,0};
    _verties[3].position = {_nodeSize.width/2,-_nodeSize.height/2,0};

    _verties[0].color = _verties[1].color = _verties[2].color = _verties[3].color = color;

    ////  LT
    _verties[0].texcoord.u = 0.0f;
    _verties[0].texcoord.v = 1.0f;
    ////
    //  LB
    _verties[1].texcoord.u = 0.0f;
    _verties[1].texcoord.v = 0.0f;
    ////
    ////  RB
    _verties[2].texcoord.u = 1.0f;
    _verties[2].texcoord.v = 1.0f;
    ////
    ////  RT
    _verties[3].texcoord.u = 1.0f;
    _verties[3].texcoord.v = 0.0f;
    
    _spriteFrame =  (NWSpriteFrame*)spriteFrame;

    return true;
}

void TestDrawNode::draw() {
//
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    if (_isVertextDirty) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(testVerties), testVerties, GL_DYNAMIC_DRAW);
        _isVertextDirty = false;
    }
//
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
//
    glActiveTexture(GL_TEXTURE0);
//
    glBindTexture(GL_TEXTURE_2D, _spriteFrame->_texture);
//
    glUniform1i(_glProgarm->getTextureUniformSlot(), 0);
//
    glEnable(GL_BLEND);
//
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
////    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
////} else {
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//
    glUniformMatrix4fv(_glProgarm->getModelViewSlot(), 1, GL_FALSE, _modelView.mat);
//    RD_CHECK_GL_ERROR();
    glUniformMatrix4fv(_glProgarm->getProjectionSlot(), 1, GL_FALSE, Director::getInstance()->getProjectionMatrix().mat);
//    RD_CHECK_GL_ERROR();
//
    glVertexAttribPointer(_glProgarm->getPositionSlot(), 3, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), 0);
//    RD_CHECK_GL_ERROR();
    glVertexAttribPointer(_glProgarm->getColorSlot(), 4, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), (GLvoid*)offsetof(NWTexVertex, color));
//    RD_CHECK_GL_ERROR();
    glVertexAttribPointer(_glProgarm->getTexCoordSlot(), 2, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), (GLvoid *)offsetof(NWTexVertex, texcoord));
    RD_CHECK_GL_ERROR();
//
    glDrawArrays(GL_TRIANGLES, 0, 3);
}


TestDrawNode::TestDrawNode() {
    glGenBuffers(1, &_vertexBuffer);
}

TestDrawNode::TestDrawNode(int a) {
    _glProgarm = NWGLProgram::createBasicProgram();
    glGenBuffers(1, &_vertexBuffer);
    testVerties[0].position = {-100,100,0};
    testVerties[1].position = {-100,-100,0};
    testVerties[2].position = {100,100,0};


    ////  LT
    testVerties[0].texcoord.u = 0.0f;
    testVerties[0].texcoord.v = 1.0f;
    ////
    //  LB
    testVerties[1].texcoord.u = 0.0f;
    testVerties[1].texcoord.v = 0.0f;
    ////
    ////  RB
    testVerties[2].texcoord.u = 1.0f;
    testVerties[2].texcoord.v = 1.0f;

    testVerties[0].color = testVerties[1].color = testVerties[2].color =  NWFloatColorMake(1.0, 0.0, 0.0, 1.0);
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
