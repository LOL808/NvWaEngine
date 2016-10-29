//
//  Director.cpp
//  NvWaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//
#include <thread>
#include "Director.h"
#include <iostream>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "GLViewImpl-iOS.h"


//TestDrawNode* globalTestDW = TestDrawNode::createWithColorAndSize(NWFloatColorMake(1.0, 0.0, 0.0, 1.0));
//
#include <time.h>
//

using namespace std;

typedef struct{
    float Position[3];
    float Color[4];
}Vertex;

const Vertex DVertices[] = {
    {{1, -1, 3}, {1, 0, 0, 1}},
    {{1, 1, 0}, {0, 1, 0, 1}},
    {{-1, 1, 0}, {0, 0, 1, 1}},
    {{-1, -1, 3}, {0, 0, 0, 1}}
};

const GLubyte DIndices[] = {
    0, 1, 2,
    2, 3, 0
};


Director* Director::_instance = nullptr;

Director* Director::getInstance() {
    if (!_instance) {
        _instance = new Director();
    }
    return _instance;
}

Director::~Director() {
    
}

Director::Director() {

}


void Director::mainLoop() {
//    cout<<"C++ thread id : "<<std::this_thread::get_id()<<endl;
    testFoo();
}

bool first = true;
void Director::testFoo() {
    if (first) {
        first = false;
        _testNode = TestDrawNode::createWithColorAndSize(NWFloatColorMake(1.0, 0, 1.0, 1.0));
//        _testNode->testFoo(100, 100, 50, 50);
    }

    glClearColor(0.8, 0.8, 0.8, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    _testNode->draw();

    _glview->draw();
//

}




void Director::setGLView(GLViewImpl *glview) {
    _glview = glview;
//    glViewport(0, 0, 300,300);
}