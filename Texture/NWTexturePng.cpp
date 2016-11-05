//
//  NWTexturePng.cpp
//  NvWaEngine
//
//  Created by /help on 11/3/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWTexture.h"
#include <stdlib.h>
#include <memory.h>

#include "png.h"

typedef struct {
    png_bytep data;
    size_t size;
    size_t offset;
}PngImageSource;


static void pngReadCallback(png_structp png_ptr, png_bytep data, png_size_t len) {
    PngImageSource* iSource = (PngImageSource*)png_get_io_ptr(png_ptr);

    if (iSource->offset+len <= iSource->size) {
        memcpy(data, iSource->data+iSource->offset, len);
        iSource->offset += len;
    }
    else {
        png_error(png_ptr, "pngReadCallback failed");
    }
}


bool NWTexture::decodePng(NWData *data) {

    png_structp png_ptr  = nullptr;
    png_infop   info_ptr = nullptr;

#define PNG_SIG_SIZE 8

    if (data->getLen()<PNG_SIG_SIZE) {
        return false;
    }

    if (png_sig_cmp(data->getData(), 0, PNG_SIG_SIZE)) {
        return false;
    }
#undef PNG_SIG_SIZE
    //allocate png_struct
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);

    if (!png_ptr) {
        return false;
    }

    //allocate png_info

    info_ptr = png_create_info_struct(png_ptr);

    if (!info_ptr) {
        png_destroy_read_struct(&png_ptr, 0, 0);
        return false;
    }

    png_infop end_info = png_create_info_struct(png_ptr);

    if (!end_info) {
        png_destroy_read_struct(&png_ptr, 0, 0);
        return false;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "error from libpng\n");
//        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
//        fclose(fp);
        return false;
    }


    PngImageSource imageSource;
    imageSource.data    = data->getData();
    imageSource.size    = data->getLen();
    imageSource.offset  = 0;

    png_set_read_fn(png_ptr, &imageSource, pngReadCallback);

    png_read_info(png_ptr, info_ptr);

    _width  = png_get_image_width(png_ptr, info_ptr);
    _height = png_get_image_height(png_ptr, info_ptr);
    png_byte bit_depth = png_get_bit_depth(png_ptr, info_ptr);
    png_uint_32 color_type = png_get_color_type(png_ptr, info_ptr);

    if (color_type == PNG_COLOR_TYPE_PALETTE) {
        png_set_palette_to_rgb(png_ptr);
    }

    if (color_type == PNG_COLOR_TYPE_GRAY&&bit_depth<8) {
        bit_depth = 8;
        png_set_expand_gray_1_2_4_to_8(png_ptr);
    }

    if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
        png_set_tRNS_to_alpha(png_ptr);
    }

    if (bit_depth == 16) {
        png_set_strip_16(png_ptr);
    }

    if (bit_depth<8) {
        png_set_packing(png_ptr);
    }

    png_read_update_info(png_ptr, info_ptr);

    bit_depth = png_get_bit_depth(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);

    switch (color_type) {
        case PNG_COLOR_TYPE_GRAY:
            _textureFormat = NW_TEXTURE_FORMAT_I8;
            break;
        case PNG_COLOR_TYPE_GRAY_ALPHA:
            _textureFormat = NW_TEXTURE_FORMAT_AI88;
            break;
        case PNG_COLOR_TYPE_RGB:
            _textureFormat = NW_TEXTURE_FORMAT_RGBA24;
            break;
        case PNG_COLOR_TYPE_RGB_ALPHA:
            _textureFormat = NW_TEXTURE_FORMAT_RGBA32;
            break;
        default:
            break;
    }

    png_bytep *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * _height);

    if (!row_pointers) {
        png_destroy_read_struct(&png_ptr, &info_ptr, 0);
        return false;
    }

    png_size_t row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    _dataLen = row_bytes*_height;
    _data = (NW_uchar*)malloc(_dataLen);

    if (!_data) {
        free(row_pointers);
        png_destroy_read_struct(&png_ptr, &info_ptr, 0);
        return false;
    }

    for (NW_uint32 i=0; i<_height; i++) {
        row_pointers[i] = _data+(_height-1-i)*row_bytes;
    }

    png_read_image(png_ptr, row_pointers);
    png_read_end(png_ptr, nullptr);


    if (color_type==PNG_COLOR_TYPE_RGB_ALPHA) {
        premultipliedAlpha();
    }
    else {
        _isPremultipliedAlpha = false;
    }

    return true;
}