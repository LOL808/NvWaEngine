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



//    std::cout<<FileHelper::getInstance()->_bundlePath;

//    NWSpriteFrame* diamond = NWSpriteFrame::create("left.png");

//    _testNode = new TestDrawNode(3);
//    _testNode = TestDrawNode::createWithSpriteFrame(diamond);
//    _testNode->setPosition(NWPointMake(100,100));

//    _sprite = NWSprite::createWithSpriteFrame(diamond);
//    _sprite->setPosition(NWPointMake(30, 30));

}


void Director::mainLoop() {
    testFoo();
    this_thread::sleep_for(chrono::milliseconds(2000));
}

bool first = true;
int deg = 0.0f;
void Director::testFoo() {
    if (first) {
        first = false;
        
//        NWSpriteFrame* frame = NWSpriteFrame::create("left.png");
//        _sprite = NWSprite::createWithSpriteFrame(frame);
        _sprite = NWSprite::createWithName("left.png");
        _sprite->setPosition(NWPointMake(100, 100));
//        _testNode = new TestDrawNode(3);
        //        _testNode = TestDrawNode::createWithColorAndSize(NWFloatColorMake(0.0,0.0, 1.0, 1.0),NWSizeMake(100,100));
//        _testNode1 = TestDrawNode::createWithColorAndSize(NWFloatColorMake(1.0, 1, 0.0, 1.0),NWSizeMake(100,100));
//        _testNode1->setPosition(NWPointMake(200, 200));
//
//        _testNode2 = TestDrawNode::createWithSprite("test.png");
////        _testNode2->setPosition(NWPointMake(50,200));
////        _testNode->setPosition(NWPointMake(50, 50));
//        NWTexture* text = NWTexture::createWithFile("test.png");
//
//        _testNode->setRotation(0);
//        _testNode1->setRotation(-30);
//        _testNode2->setRotation(30);
        glViewport(0, 0, _viewSize.width, _viewSize.height);
    }

    glClearColor(0.8, 0.8, 0.8, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


//    _testNode->draw();
    _sprite->draw();
    _glview->draw();
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
