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


char* NWFilePorting_getData(const char* fullPath, bool isText, size_t *outSize) {

    FILE* fp  = fopen(fullPath, "rb");

    if (NULL == fp) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    *outSize = (size_t)ftell(fp);

    return NULL;
}