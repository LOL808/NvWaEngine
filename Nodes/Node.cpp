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


Node::Node():_glProgarm(nullptr),_nodeSize(NWSizeMake(0, 0)){
    _glProgarm = NWGLProgram::create();
}

Node::~Node(){
    
}

void Node::draw() {
    
}