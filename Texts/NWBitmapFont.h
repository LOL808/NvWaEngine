//
//  NWBitmapFont.hpp
//  NvWaEngine
//
//  Created by cocos on 21/11/2016.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef __NVWA_ENGINE_TEXTS_NWBITMAPFONT_
#define __NVWA_ENGINE_TEXTS_NWBITMAPFONT_

#include "../Math/NWTypes.h"
#include "../Nodes/Node.h"
#include <string>
#include <map>

using namespace std;
//保存单个字符的信息
struct CharInfo {
    NW_uchar    charid;
    NW_uint32   x;
    NW_uint32   y;
    NW_uint32   width;
    NW_uint32   height;
    NW_uint32   xOffset;
    NW_uint32   yOffset;
    NW_uint32   xAdvance;
    NW_uchar    page;
    NW_uchar    chanel;
    
    CharInfo(): charid(0),
                x(0),
                y(0),
                width(0),
                height(0),
                xOffset(0),
                yOffset(0),
                xAdvance(0),
                page(0),
                chanel(0) {
    }
};
//保存bitmap的信息
struct CharSet {
//    NW_uchar    lineHeight;
//    NW_int16    scaleW;
//    NW_int16    scaleH;
//    NW_uchar    pages;
//    NW_char     charsetDesc[256];
//    NW_uchar    base;
};

class NWBitmapFont : public Node{
public:
    static NWBitmapFont* create(string text, string fntPath, string texturePath);
    
    string getString() {return _text;}
    void   setString(string text) {_text = text;}
    
private:
    NWBitmapFont(string text, string fntPath, string texturePaht);

    void parseFontFile(string fntPath);
    
    void parseCommonData(const string& data);
    void parseCharactorData(const string& data);
    
    void setupVertexAndTexture(string text);
private:
    std::map<int,CharInfo> _characters;
    string _text;
    
    NW_uchar    _lineHeight;
    NW_int16    _scaleW;
    NW_int16    _scaleH;
    NW_uchar    _pages;
//    NW_char     _charsetDesc[256];
    NW_uchar    _base;
};

//class NWBitMapFont
#endif /* NWBitmapFont_hpp */
