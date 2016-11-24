//
//  NWBitmapFont.cpp
//  NvWaEngine
//
//  Created by cocos on 21/11/2016.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWBitmapFont.h"
#include "../Utils/NWFileHelper.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    
//    string str(s);
//    str.replace("char ","");
//    str.substr();
//    str = str.erase(0,5);
    
    std::stringstream ss(s);
    
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

bool stringStartsWith(const char *prefix, const char *str) {
    return strncmp(prefix, str, strlen(prefix))==0;
}


NWBitmapFont* NWBitmapFont::create(string text, string fntPath, string texturePath) {
    NWBitmapFont* pRet = new NWBitmapFont(text, fntPath, texturePath);
    return pRet;
}

NWBitmapFont::NWBitmapFont(string text, string fntPath, string texturePath) {
    glGenBuffers(1, &_vertexBuffer);
    
    
    
    parseFontFile(fntPath);
    setupVertexAndTexture(text);
}

void NWBitmapFont::parseFontFile(string fntPath) {
    NWData* fntData = FileHelper::getInstance()->getData(NW_FILETYPE_TXT, fntPath.c_str());
    stringstream ss((char*)fntData->getData());
    string line;
    
    while (getline(ss,line)){
        if (stringStartsWith("char id", line.c_str())) {
            parseCharactorData(line);
        }
        else if (stringStartsWith("common", line.c_str())) {
            parseCommonData(line);
        }
    }
}

void NWBitmapFont::parseCommonData(const string &data) {
    vector<string> components;
    split(data, '=', components);
    for(int i=0;i<components.size();i++) {
        cout<<components[i]<<endl;
    }
    
    _lineHeight = atoi(components[1].c_str());
    _scaleW = atoi(components[3].c_str());
    _scaleH = atoi(components[4].c_str());
    
    
}

void NWBitmapFont::parseCharactorData(const string &data) {
    vector<string> components;
    split(data, '=', components);

    int charID = atoi(components[1].c_str());
    _characters[charID].x = atoi(components[2].c_str());
    _characters[charID].y = atoi(components[3].c_str());
    _characters[charID].width = atoi(components[4].c_str());
    _characters[charID].height = atoi(components[5].c_str());
    _characters[charID].xOffset = atoi(components[6].c_str());
    _characters[charID].yOffset = atoi(components[7].c_str());
    _characters[charID].xAdvance = atoi(components[8].c_str());
   
}

typedef struct {
    float vtlx,vtly,  ttlx,ttly, vblx,vbly,  tblx,tbly, vbrx,vbry,  tbrx,tbry, vtrx,vtry,  ttrx,ttry;
} font_square_t;

void NWBitmapFont::setupVertexAndTexture(string text) {
    font_square_t* charSquares = (font_square_t*)malloc(sizeof(font_square_t)*text.size());
}
