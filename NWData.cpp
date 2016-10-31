//
//  NWData.cpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWData.h"
#include <memory.h>
#include <stdlib.h>

NWData::NWData():_haveBOM(false),_data(nullptr),_len(0) {

}


NWData::~NWData() {
    if (_len>0&&_data) {
        delete [] _data;
    }
    _len = 0;
}

NWData::NWData(unsigned char* buffer, size_t len):_haveBOM(false) {
//    _data = (char*)calloc(sizeof(char*), len);
    _data = buffer;
    _len = len;
}