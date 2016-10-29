//
//  GLViewImpl.cpp
//  NvWaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//
#import "NWGLView-iOS.h"
#include "GLViewImpl-iOS.h"
#include <iostream>

GLViewImpl* GLViewImpl::create() {
    GLViewImpl* pRet = new (std::nothrow) GLViewImpl;
    if (pRet&&pRet->init()) {

        return  pRet;
    }
    delete pRet;
    pRet = nullptr;
    return pRet;
}

GLViewImpl* GLViewImpl::createWithEAGLView(void* eaglview) {
    GLViewImpl* pRet = new (std::nothrow) GLViewImpl;
    if (pRet&&pRet->initWithEAGLView(eaglview)){
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return pRet;
}

bool GLViewImpl::init() {

    NWGLView_iOS* glview = [[NWGLView_iOS alloc] init];
    _eaglview = glview;
    return true;
}

bool GLViewImpl::initWithEAGLView(void* eaglview) {
    _eaglview = eaglview;
    return true;
}

void* GLViewImpl::getEAGLView() {
    return _eaglview;
}

void GLViewImpl::draw() {
    NWGLView_iOS* view = (NWGLView_iOS*)_eaglview;
//    view
    [view render];
}

void GLViewImpl::setRenderBuffer(){
    NWGLView_iOS* view = (NWGLView_iOS*)_eaglview;
    //    view
//    [view render];
//    [view ]
}
void GLViewImpl::setFrameBuffer(GLuint handler){
    NWGLView_iOS* view = (NWGLView_iOS*)_eaglview;
    [view setRenderBuffer:handler];
}

