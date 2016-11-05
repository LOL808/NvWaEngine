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
#include "../Math/NWTypes.h"


typedef enum{
    NW_TEXTURE_FORMAT_RGBA32,
    NW_TEXTURE_FORMAT_RGBA24,
    NW_TEXTURE_FORMAT_RGB565,
    NW_TEXTURE_FORMAT_A8,
    NW_TEXTURE_FORMAT_I8,
    NW_TEXTURE_FORMAT_AI88,
    NW_TEXTURE_FORMAT_RGBA4444,
    NW_TEXTURE_FORMAT_RGB5A1,
    NW_TEXTURE_FORMAT_PVRTC4,
    NW_TEXTURE_FORMAT_PVRTC2
}NW_TEXTURE_FORMAT;

class NWTexture {
public:
    static NWTexture* createWithFile(const char* filename);


public:

    bool initWithFile(const char* filename);
    bool decodePng(NWData* data);

    void createGLTexture();
    void premultipliedAlpha();

    NWTexture();
    ~NWTexture();

public:

    NW_TEXTURE_FORMAT   _textureFormat;
    NW_uint32           _width;
    NW_uint32           _height;
    NW_uchar*            _data;
    NW_uint32           _dataLen;

    bool                _isPremultipliedAlpha;

    GLuint              _texture;


};

#endif /* NWTexture_hpp */
