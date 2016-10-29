//
//  Director.hpp
//  NvWaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//


#ifndef _NVWA_ENGINE_CORE_DIRCTOR_
#define _NVWA_ENGINE_CORE_DIRCTOR_

#include <OpenGLES/ES2/gl.h>
#include "../NvWa.h"


class GLViewImpl;

class Director{
public:
    static Director* getInstance();


    void setGLView(GLViewImpl* glview);
    GLViewImpl* getGLViewImpl() {return _glview;}

    void mainLoop();

    void testFoo();


protected:
    Director();
    ~Director();

    NWGLProgram* _glProgarm;


private:
    TestDrawNode* _testNode;
    NWSize _viewSize;
//    GLuint _posSlot;
//    GLuint _colorSlot;
    GLViewImpl* _glview;
    static Director* _instance;
};

#endif /* Director_hpp */
