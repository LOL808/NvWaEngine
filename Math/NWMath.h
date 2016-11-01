//
//  NWMath.h
//  NvWaEngine
//
//  Created by /help on 10/25/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_MATH_NWMATH_H_
#define _NVWA_ENGINE_MATH_NWMATH_H_

#include "NWTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

    void NWMath_OrthographicProjection(NWMat4 *mat4,
                                       GLfloat left,
                                       GLfloat right,
                                       GLfloat bottom,
                                       GLfloat top,
                                       GLfloat near,
                                       GLfloat far);

    void NWMath_PerspectiveProjection(NWMat4 *mat4,
                                       GLfloat left,
                                       GLfloat right,
                                       GLfloat bottom,
                                       GLfloat top,
                                       GLfloat near,
                                       GLfloat far);

    void NWMath_modelView(NWMat4 *mat4, NWVector3 *translation, NWVector3* rotation, NWVector3* scale);

    NWBitColor NWBitColorMake(NW_uchar r, NW_uchar g, NW_uchar b, NW_uchar a);

    NWFloatColor NWFloatColorMake(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    NWFloatColor NWBitColorToNWFloatColor(NWBitColor* bitColor, NWFloatColor* floatColor);

    NWSize NWSizeMake(GLfloat width, GLfloat height);

    NWPoint NWPointMake(GLfloat x, GLfloat y);

    NWVector3 NWVector3Make(GLfloat x, GLfloat y, GLfloat z);

#ifdef __cplusplus
}
#endif

#endif /* NWMath_h */
