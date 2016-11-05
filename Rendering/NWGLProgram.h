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

    GLint getPositionSlot() {return _positionSlot;}
    GLint getColorSlot() {return  _colorSlot;}
    GLint getProjectionSlot() {return _projectionUniform;}
    GLint getModelViewSlot() {return _modeViewUniform;}
    GLint getTexCoordSlot() {return _texCoordSlot;}
    GLint getTextureUniformSlot() {return _textureUniform;}

    GLint getAlphaUniform(void) {return _alphaUniform;};

    GLuint getProgram() {return _program;}



protected:

    NWGLProgram();
    ~NWGLProgram();

    bool compileShaders(const char* vshContent, const char* fshContent);
    bool linkProgram();

    bool init();
    bool initWithShaders(const char* vshContent, const char* fshContent);

private:


    GLuint _program;
    GLint _fshader;
    GLint _vshader;

    GLint _projectionUniform;
    GLint _modeViewUniform;

    GLint _positionSlot;
    GLint _colorSlot;
    GLint _texCoordSlot;
    GLint _textureUniform;
    GLint _alphaUniform;


};

#endif /* NWGLProgram_hpp */
