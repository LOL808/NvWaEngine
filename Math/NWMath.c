//
//  NWMath.c
//  NvWaEngine
//
//  Created by /help on 10/25/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWMath.h"

void NWMath_OrthographicProjection(NWMat4 *mat4,
                                   GLfloat left,
                                   GLfloat right,
                                   GLfloat bottom,
                                   GLfloat top,
                                   GLfloat near,
                                   GLfloat far) {
    mat4->mat[0] = 2.0f/(right-left);
    mat4->mat[1] = 0.0f;
    mat4->mat[2] = 0.0f;
    mat4->mat[3] = 0.0f;

    mat4->mat[4] = 0.0f;
    mat4->mat[5] = 2.0f/(top-bottom);
    mat4->mat[6] = 0.0f;
    mat4->mat[7] = 0.0f;

    mat4->mat[8] = 0.0f;
    mat4->mat[9] = 0.0f;
    mat4->mat[10] = -2.0f/(far-near);
    mat4->mat[11] = 0.0f;

    mat4->mat[12] = -(right+left)/(right-left);
    mat4->mat[13] = -(top+bottom)/(top-bottom);
    mat4->mat[14] = -(far+near)/(far-near);
    mat4->mat[15] = 1.0f;
}

void NWMath_modelView(NWMat4 *mat4, NWVector3 *translation, NWVector3* rotation, NWVector3* scale) {

    mat4->mat[0] = 1.0;
    mat4->mat[1] = 0.0;
    mat4->mat[2] = 0.0;
    mat4->mat[3] = 0.0;

    mat4->mat[4] = 0.0;
    mat4->mat[5] = 1.0;
    mat4->mat[6] = 0.0;
    mat4->mat[7] = 0.0;

    mat4->mat[8] = 0.0;
    mat4->mat[9] = 0.0;
    mat4->mat[10] = 1.0;
    mat4->mat[11] = 0.0;

    mat4->mat[12] = 0.0;
    mat4->mat[13] = 0.0;
    mat4->mat[14] = 0.0;
    mat4->mat[15] = 1.0;

}

NWBitColor NWBitColorMake(NW_uchar r, NW_uchar g, NW_uchar b, NW_uchar a) {
    NWBitColor bitColor;
    bitColor.r = r;
    bitColor.g = g;
    bitColor.b = b;
    bitColor.a = a;
    return  bitColor;
}

NWFloatColor NWBitColorToNWFloatColor(NWBitColor* bitColor, NWFloatColor* floatColor) {
    floatColor->r = bitColor->r/255.0f;
    floatColor->g = bitColor->g/255.0f;
    floatColor->b = bitColor->b/255.0f;
    floatColor->a = bitColor->a/255.0f;

    return *floatColor;
}

NWSize NWSizeMake(GLfloat width, GLfloat height) {
    NWSize size = {width, height};
    return size;
}

NWFloatColor NWFloatColorMake(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    NWFloatColor color = {r,g,b,a};
    return color;
}

NWPoint NWPointMake(GLfloat x, GLfloat y) {
    NWPoint point;
    point.x = x;
    point.y = y;
    return point;
}

NWVector3 NWVector3Make(GLfloat x, GLfloat y, GLfloat z) {
    NWVector3 vec3;
    vec3.x = x;
    vec3.y = y;
    vec3.z = z;
    return vec3;
}
void NWMath_PerspectiveProjection(NWMat4 *mat4,
                                  GLfloat left,
                                  GLfloat right,
                                  GLfloat bottom,
                                  GLfloat top,
                                  GLfloat near,
                                  GLfloat far) {
    mat4->mat[0] = 2.0/(right-left);
    mat4->mat[1] = 0.0;
    mat4->mat[2] = 0.0;
    mat4->mat[3] = 0.0;

    mat4->mat[4] = 0.0;
    mat4->mat[5] = 2.0/(top-bottom);
    mat4->mat[6] = 0.0;
    mat4->mat[7] = 0.0;

    mat4->mat[8] = 0.0;
    mat4->mat[9] = 0.0;
    mat4->mat[10] = -2.0/(far-near);
    mat4->mat[11] = 0.0;

    mat4->mat[12] = -(right+left)/(right-left);
    mat4->mat[13] = -(top+bottom)/(top-bottom);
    mat4->mat[14] = -(far+near)/(far-near);
    mat4->mat[15] = 1.0;
}

NWRect  NWRectMake(float x, float y, float width, float height) {
    NWRect rect;
    rect.origin = NWPointMake(x, y);
    rect.size = NWSizeMake(width, height);

    return rect;
}
