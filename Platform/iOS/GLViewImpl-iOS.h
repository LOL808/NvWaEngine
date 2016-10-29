//
//  GLViewImpl.hpp
//  NvWaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_PLATFORM_IOS_GLVIEWIMPL_
#define _NVWA_ENGINE_PLATFORM_IOS_GLVIEWIMPL_



class GLViewImpl {
public:
    static GLViewImpl* create();
    static GLViewImpl* createWithEAGLView(void* eaglview);

    void* getEAGLView();
//    EAGLContext* getContext() {return _context;}
    void setRenderBuffer();
    void setFrameBuffer(GLuint);

    void draw();

protected:
    bool init();
    bool initWithEAGLView(void* eaglview);

private:

    void* _eaglview;
//    EAGLContext* _o;
//    EAGLContext* _context;
//    glContext

};

#endif
