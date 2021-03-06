//
//  NWFilePorting-iOS.cpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "../Porting/NWFilePorting.h"
#include "../PlatformDefine.h"
#include <stdio.h>

char* NWFilePorting_getBundlePath() {
    NSString* str = [[NSBundle mainBundle] bundlePath];
    return strdup([str UTF8String]);
}


unsigned char* NWFilePorting_getData(const char* fullPath, bool isText, size_t *outSize) {

    unsigned char* buff;

    FILE* fp  = fopen(fullPath, "rb");

    if (NULL == fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    *outSize = (size_t)ftell(fp);
    fseek(fp, 0, SEEK_SET);

    size_t mallocSize = *outSize;

    if (isText) {
        mallocSize++;
    }

    buff = (NW_uchar *)malloc(sizeof(NW_uchar)*mallocSize);
    memset(buff, 0, mallocSize);
    if (!buff) {
        fclose(fp);
        return NULL;
    }
    size_t nread;
    nread = fread(buff, sizeof(NW_uchar), mallocSize, fp);
    fclose(fp);

    return buff;
}