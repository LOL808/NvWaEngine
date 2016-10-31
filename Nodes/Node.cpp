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


Node::Node():_glProgarm(nullptr),_nodeSize(NWSizeMake(0, 0)),_origin(NWPointMake(0, 0)){
    _glProgarm = NWGLProgram::create();
    NWMath_modelView(&_modelView, nullptr, nullptr, nullptr);
}

Node::~Node(){
    
}

void Node::draw() {
    
}