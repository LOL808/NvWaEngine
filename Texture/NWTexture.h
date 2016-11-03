//
//  NWTexture.hpp
//  NvWaEngine
//
//  Created by /help on 11/3/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_TEXTURE_NWTEXTURE_H_
#define _NVWA_ENGINE_TEXTURE_NWTEXTURE_H_


#include "../Core/NWData.h"

class NWTexture {
public:
    static NWTexture* createWithFile(const char* filename);


private:

    bool initWithFile(const char* filename);
    bool decodePng(NWData* data);


    NWTexture();
    ~NWTexture();



};

#endif /* NWTexture_hpp */
