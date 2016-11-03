//
//  Node.cpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "Node.h"
#include "../Math/NWMath.h"
#include <memory.h>


Node* Node::create() {
    return nullptr;
}


Node::Node():
    _glProgarm(nullptr),
    _nodeSize(NWSizeMake(0, 0)),
    _origin(NWPointMake(0, 0)),
    _isVertextDirty(true),
    _isModelViewDirty(true),
    _rataion(0)
    {
    _glProgarm = NWGLProgram::create();
    NWMath_modelView(&_modelView, nullptr, nullptr, nullptr);

//    _origin.x = _modelView

}

void Node::setPosition(const NWVector2 &vec) {
    _origin.x = vec.x;
    _origin.y = vec.y;

    _modelView.mat[12] = vec.x;
    _modelView.mat[13] = vec.y;
    _isVertextDirty = true;
}

void Node::setRotation(float degree) {
//    rotateAroundZ(&_modelView, degree);
    NWMat4 temp;
    rotateAroundZ(&temp, degree);
    NWMat4 rlt;
    matMultiply(&rlt, &_modelView, &temp);

    memcpy((void*)&_modelView, (void*)&rlt, sizeof(NWMat4));

    _rataion = degree;
    _isModelViewDirty = true;
}

void Node::setColor(const NWFloatColor &color) {
    _verties[0].color = _verties[1].color = _verties[2].color = _verties[3].color = color;
    _isVertextDirty = true;
}

Node::~Node(){
    
}

void Node::draw() {
    
}