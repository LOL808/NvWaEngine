//
//  NWFilePorting-iOS.cpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "../Porting/NWFilePorting.h"
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

    buff = (unsigned char*)calloc(sizeof(unsigned char), mallocSize);

    if (!buff) {
        fclose(fp);
        return NULL;
    }

    fread(buff, sizeof(unsigned char), *outSize, fp);
    fclose(fp);

    return buff;
}