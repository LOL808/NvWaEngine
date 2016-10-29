//
//  NWMatMath.h
//  NvWaEngine
//
//  Created by /help on 10/25/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_MATH_NWMATMATH_H_
#define _NVWA_ENGINE_MATH_NWMATMATH_H_

#include "NWTypes.h"

#define DegreesToRadiansFactor  0.017453292519943f			// PI / 180
#define RadiansToDegreesFactor  57.29577951308232f			// 180 / PI
#define DegreesToRadians(D) ((D) * DegreesToRadiansFactor)
#define RadiansToDegrees(R) ((R) * RadiansToDegreesFactor)

#ifdef __cplusplus__
extern "C" {
#endif

    //get the length of a Vector3
    float getVector3Length(const NWVector3* vecInput);
    //
    NWVector3* normalizeVector3(NWVector3* vecOutput, const NWVector3* vecInput);


    NWVector3* getTranslationFromMat(NWVector3* vecOutput ,const NWMat4* matInput);

    NWVector3* getRotationFromMat(NWVector3* vecOutput,const NWMat4* matInput);

    NWVector3* getScaleFromMat(NWVector3* vecOutput, const NWMat4* matInput);

    NWMat4* matMultiply(NWMat4* matOutput, const NWMat4* matInputF, const NWMat4* matInputL);

    NWMat4* revserMat(NWMat4* matOut, const NWMat4* matInput);

    NWMat4* rotateAroundX(NWMat4* matOutput, float degrees);
    NWMat4* rotateAroundY(NWMat4* matOutput, float degrees);
    NWMat4* rotateAroundZ(NWMat4* matOutput, float degrees);


#ifdef __cplusplus__
}
#endif

#endif /* NWMatMath_h */
