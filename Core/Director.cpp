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
#include <chrono>
#include <thread>
#include <fstream>


clock_t deltaTime = 0;
unsigned int frames = 0;
double  frameRate = 60;
double  averageFrameTimeMilliseconds = 16.666666;


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
    testFoo();
    this_thread::sleep_for(chrono::milliseconds(16));
}

bool first = true;
int deg = 0.0f;
void Director::testFoo() {
    if (first) {
        first = false;
        
        NWBitmapFont* font = NWBitmapFont::create("hello", "bmf.fnt", "bmf_0.png");
        
//        _sprite = NWSprite::createWithName("bmf_0.png");
//        _sprite->setPosition(NWPointMake(100, 100));
//        _sprite->setRotation(45);
//        _sprite->setRotation(45);
        glViewport(0, 0, _viewSize.width, _viewSize.height);
    }

    clock_t beginTime = clock();
    
    glClearColor(0.8, 0.8, 0.8, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
//    _sprite->setRotation(10);


//    _testNode->draw();
//    _sprite->draw();
    _glview->draw();
    
    clock_t endTime = clock();
    deltaTime = endTime - beginTime;
//    cout<<deltaTime<<endl;
//    
//    if( clockToMilliseconds(deltaTime)>1000.0){ //every second
//        frameRate = (double)frames*0.5 +  frameRate*0.5; //more stable
//        frames = 0;
//        deltaTime -= CLOCKS_PER_SEC;
//        averageFrameTimeMilliseconds  = 1000.0/(frameRate==0?0.001:frameRate);
//        
//        if(vsync)
//            std::cout<<"FrameTime was:"<<averageFrameTimeMilliseconds<<std::endl;
//        else
//            std::cout<<"CPU time was:"<<averageFrameTimeMilliseconds<<std::endl;
//    }
//
}




void Director::setGLView(GLViewImpl *glview) {
    _glview = glview;
}

void Director::setUpProjectionMatrix(const float width, const float height) {
//    NWMath_PerspectiveProjection(&_projectionMatrix, -width/2, width/2, 0, height, -128, 128);
    NWMath_OrthographicProjection(&_projectionMatrix, 0, width, 0, height, -128, 128);
    _viewSize = NWSizeMake(width, height);
}
