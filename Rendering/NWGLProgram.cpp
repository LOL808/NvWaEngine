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
#include "../Utils/NWFileHelper.h"


const char* s_vsh ="\
attribute vec4 Position;\
attribute vec4 SourceColor;\
attribute vec2 TexCoordIn;\
\
uniform mat4 ModelView;\
uniform mat4 Projection;\
varying vec4 DestColor;\
varying vec2 TexCoordOut;\
\
void main(void) {\
    DestColor   = SourceColor;\
    gl_Position = Projection*ModelView*Position;\
    TexCoordOut = TexCoordIn;\
}";



const char* s_fsh ="\
precision lowp float;\
\
varying lowp vec4 DestColor;\
varying lowp vec2 TexCoordOut;\
uniform sampler2D Texture;\
void main(void){\
    vec4 texColor = texture2D(Texture,TexCoordOut);\
    if(texColor.a>0.1)  \
     gl_FragColor = texColor*DestColor;\
    else\
     gl_FragColor = DestColor;\
}";


//uniform mat4 Projection

const char* bs_vsh ="\
attribute vec4 Position;\
attribute vec4 SourceColor;\
\
uniform mat4 ModelView;\
uniform mat4 Projection;\
varying vec4 DestColor;\
\
void main(void) {\
DestColor   = SourceColor;\
gl_Position = Projection*ModelView*Position;\\
}";



const char* bs_fsh ="\
precision lowp float;\
\
varying lowp vec4 DestColor;\
void main(void){\
gl_FragColor = DestColor;\
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

NWGLProgram* NWGLProgram::createBasicProgram() {
    NWGLProgram* pRet = new NWGLProgram();
    if (pRet&&pRet->initWithShaders(bs_vsh , bs_fsh)) {
        return pRet;
    }
    return nullptr;
}

bool NWGLProgram::init() {

//    NWData* vsh = FileHelper::getInstance()->getData(NW_FILETYPE_TXT, "",true);

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
        _texCoordSlot = glGetAttribLocation(_program, "TexCoordIn");

        glEnableVertexAttribArray(_modeViewUniform);
        glEnableVertexAttribArray(_projectionUniform);
        glEnableVertexAttribArray(_positionSlot);
        glEnableVertexAttribArray(_colorSlot);

        _texCoordSlot = glGetAttribLocation(_program, "TexCoordIn");
        if (_texCoordSlot >= 0) {
            glEnableVertexAttribArray(_texCoordSlot);
//
            _textureUniform = glGetUniformLocation(_program, "Texture");
        }

//        _alphaUniform = glGetUniformLocation(_program, "AlphaValue");


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
