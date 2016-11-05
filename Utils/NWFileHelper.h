//
//  FileHelper.hpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_UTILS_NWFILEHELPER_
#define _NVWA_ENGINE_UTILS_NWFILEHELPER_

#include "../Core/NWData.h"

enum NW_FILETYPE {
    NW_FILETYPE_PNG,
    NW_FILETYPE_TXT
};

class FileHelper final {
public:

    static FileHelper* getInstance();

    NWData* getData(NW_FILETYPE type,const char* filename, bool isText=false);

    char* appendPath(const char* former,const char* later);


private:

    FileHelper();
    ~FileHelper();

public:


    static FileHelper* _instance;

    char* _bundlePath;
    char* _resPath;

};


#endif
