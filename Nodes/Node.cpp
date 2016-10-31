//
//  Node.cpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "Node.h"
#include "../Math/NWMath.h"


Node* Node::create() {
    return nullptr;
}


Node::Node():
    _glProgarm(nullptr),
    _nodeSize(NWSizeMake(0, 0)),
    _origin(NWPointMake(0, 0)),
    _isVertextDirty(true),
    _isModelViewDirty(true)
    {
    _glProgarm = NWGLProgram::create();
    NWMath_modelView(&_modelView, nullptr, nullptr, nullptr);
}

void Node::setPosition(const NWVector2 &vec) {
    _origin.x = vec.x;
    _origin.y = vec.y;

    _modelView.mat[12] = vec.x;
    _modelView.mat[13] = vec.y;

}

Node::~Node(){
    
}

void Node::draw() {
    
}