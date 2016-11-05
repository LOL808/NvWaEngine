//
//  NWTexture.cpp
//  NvWaEngine
//
//  Created by /help on 11/3/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWTexture.h"
#include "../Utils/NWFileHelper.h"
#include <stdlib.h>
#include "../Utils/NWMacro.h"


#define RD_RGB_PREMULTIPLY_ALPHA(vr, vg, vb, va) \
(NW_uint32)(((NW_uint32)((NW_uchar)(vr) * ((NW_uchar)(va) + 1)) >> 8) | \
((NW_uint32)((NW_uchar)(vg) * ((NW_uchar)(va) + 1) >> 8) << 8) | \
((NW_uint32)((NW_uchar)(vb) * ((NW_uchar)(va) + 1) >> 8) << 16) | \
((NW_uint32)(NW_uchar)(va) << 24))

void NWTexture::premultipliedAlpha(void)
{
//    RD_ASSERT(_format == RD_TEXTURE_FORMAT_RGBA32, "premultipliedAlpha should be RGBA32!");

    NW_uint32 *fourBytes = (NW_uint32 *)_data;
    for (NW_uint32 i = 0; i < _width * _height; i++) {
        NW_uchar *p = _data + i * 4;
        fourBytes[i] = RD_RGB_PREMULTIPLY_ALPHA(p[0], p[1], p[2], p[3]);
    }

    _isPremultipliedAlpha = true;
}
#undef RD_RGB_PREMULTIPLY_ALPHA

NWTexture* NWTexture::createWithFile(const char *filename) {
    NWTexture* pRet = new NWTexture;
    if (pRet&&pRet->initWithFile(filename)) {
        return pRet;
    }
    delete  pRet;
    pRet = nullptr;
    return nullptr;

}

bool NWTexture::initWithFile(const char *filename) {

    NWData* data = FileHelper::getInstance()->getData(NW_FILETYPE_PNG, filename);
    _data = data->getData();
    if (!data) {
        return false;
    }

    bool ret = false;

    ret = decodePng(data);

//    delete data;

    if (!ret) {
        return false;
    }

    createGLTexture();

    return true;
}

NWTexture::NWTexture() {

}

NWTexture::~NWTexture() {

}

void NWTexture::createGLTexture() {

    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    switch (_textureFormat) {
        case NW_TEXTURE_FORMAT_RGBA32:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
            break;
        case NW_TEXTURE_FORMAT_RGBA24:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)_width, (GLsizei)_height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
            break;
        case NW_TEXTURE_FORMAT_RGBA4444:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, _data);
            break;
        case NW_TEXTURE_FORMAT_RGB5A1:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, _data);
            break;
        case NW_TEXTURE_FORMAT_RGB565:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)_width, (GLsizei)_height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, _data);
            break;
        case NW_TEXTURE_FORMAT_AI88:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE_ALPHA, (GLsizei)_width, (GLsizei)_height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, _data);
            break;
        case NW_TEXTURE_FORMAT_A8:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, (GLsizei)_width, (GLsizei)_height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, _data);
            break;
        case NW_TEXTURE_FORMAT_I8:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, (GLsizei)_width, (GLsizei)_height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, _data);
            break;
//            RD_ASSERT(0, "Unknown texture format");
        default:
            break;
    }

    if (_data) {
        free(_data);
        _data = nullptr;
    }

}