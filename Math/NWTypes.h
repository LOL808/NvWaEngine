//
//  NWTypes.h
//  NvWaEngine
//
//  Created by /help on 10/25/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_MATH_NWTYPES_
#define _NVWA_ENGINE_MATH_NWTYPES_


//iOS
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#include "../Platform/PlatformDefine.h"
////////////

typedef struct NWPoint {
    GLfloat x;
    GLfloat y;
}NWPoint;


typedef struct NWSize {
    GLfloat width;
    GLfloat height;
}NWSize;

typedef struct NWRect{
    NWPoint origin;
    NWSize  size;
}NWRect;

typedef NWPoint NWVector2;

typedef struct NWVector3{
    GLfloat x;
    GLfloat y;
    GLfloat z;
}NWVector3;

typedef struct NWBitColor{
    NW_uchar r;
    NW_uchar g;
    NW_uchar b;
    NW_uchar a;
}NWBitColor;

typedef struct NWFloatColor{
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
}NWFloatColor;

typedef struct NWTexCoord{
    GLfloat u;
    GLfloat v;
}NWTexCoord;

typedef struct NWQuaternion{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
}NWQuaternion;

typedef struct NWMat4{
    GLfloat mat[16];
}NWMat4;

typedef struct NWBaiscVertex{
    NWVector3       position;
    NWFloatColor    color;
}NWBaiscVertex;

typedef struct NWTexVertex{
    NWVector3       position;
    NWFloatColor    color;
    NWTexCoord      texcoord;
}NWTexVertex;


//






#endif
