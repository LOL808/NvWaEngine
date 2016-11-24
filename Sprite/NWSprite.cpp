//
//  NWSprite.cpp
//  NvWaEngine
//
//  Created by /help on 11/5/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWSprite.h"
#include "NWSpriteFrame.h"
#include "../Core/Director.h"
#include "NWSpriteFrameCache.h"

NWSprite* NWSprite::createWithSpriteFrame(const NWSpriteFrame *spriteFrame) {
    NWSprite* pRet = new NWSprite(spriteFrame);
    if (pRet) {
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

NWSprite* NWSprite::createWithName(const std::string name) {
    NWSpriteFrame* frame = NWSpriteFrameCache::getInstance()->getSpriteFrame(name);
    if (frame==nullptr) {
        frame = NWSpriteFrame::create(name.c_str());
        NWSpriteFrameCache::getInstance()->addSpriteFrame(name, frame);
    }
    return NWSprite::createWithSpriteFrame(frame);
}

NWSprite::NWSprite(const NWSpriteFrame* spriteFrame) {
    //生成buffer
    glGenBuffers(1, &_vertexBuffer);

    GLfloat left;
    GLfloat right;
    GLfloat top;
    GLfloat bottom;

    left = 1.0;
    right = 0.0;
    top = 1.0;
    bottom = 0.0;

    _nodeSize = spriteFrame->_size;
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

}



void NWSprite::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    if (_isVertextDirty) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(_verties), _verties, GL_DYNAMIC_DRAW);
        _isVertextDirty = false;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    glActiveTexture(GL_TEXTURE0);

    glBindTexture(GL_TEXTURE_2D, _spriteFrame->_texture);

    glUniform1i(_glProgarm->getTextureUniformSlot(), 0);

    glEnable(GL_BLEND);

    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glUniformMatrix4fv(_glProgarm->getModelViewSlot(), 1, GL_FALSE, _modelView.mat);
    glUniformMatrix4fv(_glProgarm->getProjectionSlot(), 1, GL_FALSE, Director::getInstance()->getProjectionMatrix().mat);

    glVertexAttribPointer(_glProgarm->getPositionSlot(), 3, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), 0);
    glVertexAttribPointer(_glProgarm->getColorSlot(), 4, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), (GLvoid*)offsetof(NWTexVertex, color));
    glVertexAttribPointer(_glProgarm->getTexCoordSlot(), 2, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), (GLvoid *)offsetof(NWTexVertex, texcoord));
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

NWSprite::~NWSprite() {
    
}
