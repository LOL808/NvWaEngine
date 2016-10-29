//
//  NWGLProgram.hpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_RENDERING_NWGLPROGRAM_
#define _NVWA_ENGINE_RENDERING_NWGLPROGRAM_

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class NWGLProgram {
public:

    static NWGLProgram* create();
    static NWGLProgram* create(const char* vshContent, const char* fshContent);

    GLuint getPositionSlot() {return _positionSlot;}
    GLuint getColorSlot() {return  _colorSlot;}
    GLuint getProjectionSlot() {return _projectionUniform;}
    GLuint getModelViewSlot() {return _modeViewUniform;}

protected:

    NWGLProgram();
    ~NWGLProgram();

    bool compileShaders(const char* vshContent, const char* fshContent);
    bool linkProgram();

    bool init();
    bool initWithShaders(const char* vshContent, const char* fshContent);

private:


    GLuint _program;
    GLuint _fshader;
    GLuint _vshader;

    GLuint _projectionUniform;
    GLuint _modeViewUniform;

    GLuint _positionSlot;
    GLuint _colorSlot;

};

#endif /* NWGLProgram_hpp */
