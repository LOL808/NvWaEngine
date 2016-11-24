//
//  NWMatMath.c
//  NvWaEngine
//
//  Created by /help on 10/25/16.
//  Copyright © 2016 /help. All rights reserved.
//


#include "NWMatMath.h"
#include <math.h>


//
//  m0 m4 m8   m12
//
//  m1 m5 m9   m13
//
//  m2 m6 m10  m14
//
//  m3 m7 m11  m15
//
//  m12 m13 m14 表示 x,y,z上的平移
//



//get the length of a Vector3
float getVector3Length(const NWVector3* vecInput) {
    return  sqrtf(vecInput->x*vecInput->x+vecInput->y*vecInput->y+vecInput->z*vecInput->z);
}
//
NWVector3* normalizeVector3(NWVector3* vecOutput, const NWVector3* vecInput) {

    GLfloat l = 1.0f/getVector3Length(vecInput);

    vecOutput->x = vecInput->x*l;
    vecOutput->y = vecInput->y*l;
    vecOutput->z = vecInput->z*l;

    return vecOutput;
}


NWVector3* getTranslationFromMat(NWVector3* vecOutput ,const NWMat4* matInput) {

    vecOutput->x = matInput->mat[12];
    vecOutput->y = matInput->mat[13];
    vecOutput->z = matInput->mat[14];

    return vecOutput;
}





NWVector3* getRotationFromMat(NWVector3* vecOutput,const NWMat4* matInput);


NWMat4* rotateAroundX(NWMat4* matOutput, float degrees) {
/*
     |  1  0       0       0 |
 M = |  0  cos(A) -sin(A)  0 |
     |  0  sin(A)  cos(A)  0 |
     |  0  0       0       1 |
*/
    GLfloat* m = matOutput->mat;

    m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = 0.0f;

    m[4] = 0.0f;
    m[5] = cosf(DegreesToRadians(degrees));
    m[6] = sinf(DegreesToRadians(degrees));
    m[7] = 0.0f;

    m[8] = 0.0f;
    m[9] = -sinf(DegreesToRadians(degrees));
    m[10] = cosf(DegreesToRadians(degrees));
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;

    return matOutput;
}

NWMat4* rotateAroundY(NWMat4* matOutput, float degrees) {
/*
     |  cos(A)  0   sin(A)  0 |
 M = |  0       1   0       0 |
     | -sin(A)  0   cos(A)  0 |
     |  0       0   0       1 |
*/
    GLfloat* m = matOutput->mat;
    m[0] = cosf(DegreesToRadians(degrees));
    m[1] = 0.0f;
    m[2] = -sinf(DegreesToRadians(degrees));
    m[3] = 0.0f;


    m[4] = 0.0f;
    m[5] = 1.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;

    m[8] = sinf(DegreesToRadians(degrees));
    m[9] = 0.0f;
    m[10] = cosf(DegreesToRadians(degrees));
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;

    return matOutput;
}


NWMat4* rotateAroundZ(NWMat4* matOutput, float degrees) {
/*
     |  cos(A)  -sin(A)   0   0 |
 M = |  sin(A)   cos(A)   0   0 |
     |  0        0        1   0 |
     |  0        0        0   1 |
*/
    GLfloat* m = matOutput->mat;

    m[0] = cosf(DegreesToRadians(degrees));
    m[1] = sinf(DegreesToRadians(degrees));
    m[2] = 0.0f;
    m[3] = 0.0f;

    m[4] = -sinf(DegreesToRadians(degrees));
    m[5] = cosf(DegreesToRadians(degrees));
    m[6] = 0.0f;
    m[7] = 0.0f;

    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = 1.0f;
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;

    return matOutput;
}


static GLfloat determinnat(const NWMat4* mat4) {
    const GLfloat *m = mat4->mat;
    GLfloat a0 = m[0] * m[5] - m[1] * m[4];
    GLfloat a1 = m[0] * m[6] - m[2] * m[4];
    GLfloat a2 = m[0] * m[7] - m[3] * m[4];
    GLfloat a3 = m[1] * m[6] - m[2] * m[5];
    GLfloat a4 = m[1] * m[7] - m[3] * m[5];
    GLfloat a5 = m[2] * m[7] - m[3] * m[6];
    GLfloat b0 = m[8] * m[13] - m[9] * m[12];
    GLfloat b1 = m[8] * m[14] - m[10] * m[12];
    GLfloat b2 = m[8] * m[15] - m[11] * m[12];
    GLfloat b3 = m[9] * m[14] - m[10] * m[13];
    GLfloat b4 = m[9] * m[15] - m[11] * m[13];
    GLfloat b5 = m[10] * m[15] - m[11] * m[14];

    // Calculate the determinant.
    return (a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0);
}


NWVector3* getScaleFromMat(NWVector3* vecOutput, const NWMat4* matInput) {
    vecOutput->x = sqrtf( matInput->mat[0]*matInput->mat[0] + matInput->mat[1]*matInput->mat[1] + matInput->mat[2]*matInput->mat[2] );
    vecOutput->y = sqrtf( matInput->mat[4]*matInput->mat[4] + matInput->mat[5]*matInput->mat[5] + matInput->mat[6]*matInput->mat[6] );
    vecOutput->z = sqrtf( matInput->mat[8]*matInput->mat[8] + matInput->mat[9]*matInput->mat[9] + matInput->mat[10]*matInput->mat[10]);
    return vecOutput;
}

NWMat4* matMultiply(NWMat4* matOutput, const NWMat4* matInputF, const NWMat4* matInputL) {

    const float *m1 = matInputF->mat;
    const float *m2 = matInputL->mat;

    float *m = matOutput->mat;

    m[0] = m1[0] * m2[0] + m1[4] * m2[1] + m1[8] * m2[2] + m1[12] * m2[3];
    m[1] = m1[1] * m2[0] + m1[5] * m2[1] + m1[9] * m2[2] + m1[13] * m2[3];
    m[2] = m1[2] * m2[0] + m1[6] * m2[1] + m1[10] * m2[2] + m1[14] * m2[3];
    m[3] = m1[3] * m2[0] + m1[7] * m2[1] + m1[11] * m2[2] + m1[15] * m2[3];

    m[4] = m1[0] * m2[4] + m1[4] * m2[5] + m1[8] * m2[6] + m1[12] * m2[7];
    m[5] = m1[1] * m2[4] + m1[5] * m2[5] + m1[9] * m2[6] + m1[13] * m2[7];
    m[6] = m1[2] * m2[4] + m1[6] * m2[5] + m1[10] * m2[6] + m1[14] * m2[7];
    m[7] = m1[3] * m2[4] + m1[7] * m2[5] + m1[11] * m2[6] + m1[15] * m2[7];

    m[8] = m1[0] * m2[8] + m1[4] * m2[9] + m1[8] * m2[10] + m1[12] * m2[11];
    m[9] = m1[1] * m2[8] + m1[5] * m2[9] + m1[9] * m2[10] + m1[13] * m2[11];
    m[10] = m1[2] * m2[8] + m1[6] * m2[9] + m1[10] * m2[10] + m1[14] * m2[11];
    m[11] = m1[3] * m2[8] + m1[7] * m2[9] + m1[11] * m2[10] + m1[15] * m2[11];

    m[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8] * m2[14] + m1[12] * m2[15];
    m[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9] * m2[14] + m1[13] * m2[15];
    m[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];
    m[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];


    return matOutput;
}

NWMat4* revserMat(NWMat4* matOut, const NWMat4* matInput);
