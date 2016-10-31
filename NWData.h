//
//  NWData.hpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_UTILS_NWDATA_H_
#define _NVWA_ENGINE_UTILS_NWDATA_H_

#include <stdio.h>
#include <stddef.h>

//#include <>


class NWData {
public:
    NWData();
    NWData(unsigned char* data, size_t size);
    ~NWData();

    void setBOM(bool bom) {_haveBOM = bom;}

    bool getBOM() {return _haveBOM;}

    unsigned char* getData() {return _haveBOM? _data+3:_data; }

    size_t getLen() {return _haveBOM? _len-3:_len;}

private:

    bool    _haveBOM;
    size_t  _len;
    unsigned char*   _data;

};

#endif /* NWData_hpp */
