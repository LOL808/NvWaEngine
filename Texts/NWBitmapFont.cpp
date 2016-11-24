//
//  NWBitmapFont.cpp
//  NvWaEngine
//
//  Created by cocos on 21/11/2016.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWBitmapFont.h"
#include "../Utils/NWFileHelper.h"
#include "../Core/Director.h"
#include "../Sprite/NWSpriteFrame.h"
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
    
    _spriteFrame = NWSpriteFrame::create(texturePath.c_str());
    
    
    parseFontFile(fntPath);
    setupVertexAndTexture(text,60);
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

void NWBitmapFont::setupVertexAndTexture(string text, float height) {
    float scale = height/_lineHeight;
    
    _fontVerties = new NWTexVertex[4];
    
    
    NWSize textureSize = _spriteFrame->_size;
    
    CharInfo info = _characters[text[0]];
    
//    _nodeSize = _spriteFrame->_size;
//    //    _nodeSize = NWSizeMake(50, 50);
//    
    NWFloatColor color = NWFloatColorMake(1.0, 0.0, 0.0, 1.0);
//    _fontVerties[0].position = {0,0,0};
//    _fontVerties[1].position = {float(info.width),0,0};
//    _fontVerties[2].position = {float(info.width),float(info.height),0};
//    _fontVerties[3].position = {float(info.width), float(info.height),0};
//
//    _verties[0].position = {-_nodeSize.width/2,_nodeSize.height/2,0};
//    _verties[1].position = {-_nodeSize.width/2,-_nodeSize.height/2,0};
//    _verties[2].position = {_nodeSize.width/2,_nodeSize.height/2,0};
//    _verties[3].position = {_nodeSize.width/2,-_nodeSize.height/2,0};
    
    _fontVerties[0].position = {0,0,0};
    _fontVerties[1].position = {0,float(info.height),0};
    _fontVerties[2].position = {float(info.width),0,0};
    _fontVerties[3].position = {float(info.width),float(info.height),0};
    

    _fontVerties[0].color = NWFloatColorMake(1.0, 0.0, 0.0, 1.0);
    _fontVerties[1].color = NWFloatColorMake(1.0, 1.0, 0.0, 1.0);
    _fontVerties[2].color = NWFloatColorMake(0.0, 0.0, 1.0, 1.0);
    _fontVerties[3].color = NWFloatColorMake(0.0, 1.0, 0.0, 1.0);
;

    //  LB
    float t = 1.0;
    _fontVerties[0].texcoord.u = info.x/_spriteFrame->_size.width;
    _fontVerties[0].texcoord.v = 1-(info.y+info.height)/_spriteFrame->_size.height;
    //  LT
    _fontVerties[1].texcoord.u = info.x/_spriteFrame->_size.width;
    _fontVerties[1].texcoord.v = 1-info.y/_spriteFrame->_size.height;
    //  RB
    _fontVerties[2].texcoord.u = (info.x+info.width)/_spriteFrame->_size.width;
    _fontVerties[2].texcoord.v = 1-(info.y+info.height)/_spriteFrame->_size.height;
    
    //  RT
    _fontVerties[3].texcoord.u = (info.x+info.width)/_spriteFrame->_size.width;
    _fontVerties[3].texcoord.v = 1-info.y/_spriteFrame->_size.height;
    
//    //  LT
//    _fontVerties[0].texcoord.u = info.x/_spriteFrame->_size.width;
//    _fontVerties[0].texcoord.v = info.y/_spriteFrame->_size.height;
//    //  LB
//    _fontVerties[1].texcoord.u = info.x/_spriteFrame->_size.width;;
//    _fontVerties[1].texcoord.v = (info.y+info.height)/_spriteFrame->_size.height;
//    //  RT
//    _fontVerties[2].texcoord.u = (info.x+info.width)/_spriteFrame->_size.width;
//    _fontVerties[2].texcoord.v = info.y/_spriteFrame->_size.height;
//    
//    //  RB
//    _fontVerties[3].texcoord.u = (info.x+info.width)/_spriteFrame->_size.width;;
//    _fontVerties[3].texcoord.v = (info.y+info.height)/_spriteFrame->_size.height;
//    
    
    
}

void NWBitmapFont::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    if (_isVertextDirty) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(NWTexVertex)*4, _fontVerties, GL_DYNAMIC_DRAW);
        _isVertextDirty = false;
    }
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    
    glActiveTexture(GL_TEXTURE0);
    
    glBindTexture(GL_TEXTURE_2D, _spriteFrame->_texture);
    
    glUniform1i(_glProgarm->getTextureUniformSlot(), 0);
    
    glEnable(GL_BLEND);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    
    glUniformMatrix4fv(_glProgarm->getModelViewSlot(), 1, GL_FALSE, _modelView.mat);
    glUniformMatrix4fv(_glProgarm->getProjectionSlot(), 1, GL_FALSE, Director::getInstance()->getProjectionMatrix().mat);
    
    glVertexAttribPointer(_glProgarm->getPositionSlot(), 3, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), 0);
    glVertexAttribPointer(_glProgarm->getColorSlot(), 4, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), (GLvoid*)offsetof(NWTexVertex, color));
    glVertexAttribPointer(_glProgarm->getTexCoordSlot(), 2, GL_FLOAT, GL_FALSE,
                          sizeof(NWTexVertex), (GLvoid *)offsetof(NWTexVertex, texcoord));
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
}
