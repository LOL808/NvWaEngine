//
//  NWGLProgram.cpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWGLProgram.h"
#include "NWMacro.h"
#include <string.h>
#include <stdio.h>
//#include "../Math/NWTypes.h"


const char* s_fsh ="varying lowp vec4 DestColor;\
void main(void){\
gl_FragColor = DestColor;\
}";
//uniform mat4 Projection
const char* s_vsh =
"attribute vec4 Position;\
attribute vec4 SourceColor;\
\
uniform mat4 ModelView;\
uniform mat4 Projection;\
varying vec4 DestColor;\
void main(void) {\
DestColor = SourceColor;\
gl_Position = Projection*ModelView*Position;\
}";


NWGLProgram* NWGLProgram::create() {
    NWGLProgram* pRet = new NWGLProgram();
    if (pRet&&pRet->init()) {
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

bool NWGLProgram::init() {
    return initWithShaders(s_vsh, s_fsh);
}

bool NWGLProgram::initWithShaders(const char *vshContent, const char *fshContent) {
    bool bRet = false;
    do {
    
        BREAK_IF(!compileShaders(vshContent, fshContent));
        BREAK_IF(!linkProgram());

        glUseProgram(_program);

        _positionSlot = glGetAttribLocation(_program, "Position");
        _colorSlot = glGetAttribLocation(_program, "SourceColor");

        _projectionUniform = glGetUniformLocation(_program, "Projection");
        _modeViewUniform = glGetUniformLocation(_program, "ModelView");

        glEnableVertexAttribArray(_modeViewUniform);
        glEnableVertexAttribArray(_projectionUniform);
        glEnableVertexAttribArray(_positionSlot);
        glEnableVertexAttribArray(_colorSlot);

        bRet = true;
    } while (0);
    return bRet;
}

bool NWGLProgram::compileShaders(const char *vshContent, const char *fshContent) {

    _vshader = glCreateShader(GL_VERTEX_SHADER);
    int vshLen = strlen(vshContent);
    glShaderSource(_vshader, 1, &vshContent, &vshLen);
    glCompileShader(_vshader);

    GLint vshaderCompileRlt = 0;
    glGetShaderiv(_vshader, GL_COMPILE_STATUS, &vshaderCompileRlt);
            if (vshaderCompileRlt==GL_FALSE) {
                char buffer[512];
                glGetShaderInfoLog(_vshader, 512, 0, &buffer[0]);
                printf("%s", buffer);
            }
    _fshader = glCreateShader(GL_FRAGMENT_SHADER);
    int fshLen = strlen(fshContent);
    glShaderSource(_fshader, 1, &fshContent, &fshLen);
    glCompileShader(_fshader);

    

    GLint fshaderCompileRlt = 0;
    glGetShaderiv(_fshader, GL_COMPILE_STATUS, &fshaderCompileRlt);


    if (fshaderCompileRlt==GL_FALSE) {
        char buffer[512];
        glGetShaderInfoLog(_fshader, 512, 0, &buffer[0]);
        printf("%s", buffer);
    }

    if (vshaderCompileRlt==GL_TRUE&&fshaderCompileRlt==GL_TRUE)
        return true;
    return false;
}

bool NWGLProgram::linkProgram() {

    _program =glCreateProgram();

    glAttachShader(_program, _fshader);
    glAttachShader(_program, _vshader);

    glLinkProgram(_program);

    int linkRlt=0;
    glGetProgramiv(_program, GL_LINK_STATUS, &linkRlt);
    if (linkRlt==GL_TRUE)
        return true;
    else {
        char buffer[512];
        glGetProgramInfoLog(_program, 512, 0, &buffer[0]);
        printf("%s", buffer);
    }
    printf("=========link failed");
//    glDetachShader(_program, _vshader);
//    glDetachShader(_program, _fshader);

    return false;
}

NWGLProgram::NWGLProgram():
_program(0),
_positionSlot(-1),
_colorSlot(-1),
_fshader(0),
_vshader(0),
_projectionUniform(-1),
_modeViewUniform(-1)
{

}

NWGLProgram::~NWGLProgram() {
    if (_program) {
        glDeleteProgram(_program);
    }
    if (_vshader) {
        glDeleteShader(_vshader);
    }
    if (_fshader) {
        glDeleteShader(_fshader);
    }
}