//
//  NWFilePorting-iOS.cpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "../Porting/NWFilePorting.h"

char* NWFilePorting_getBundlePath() {
    NSString* str = [[NSBundle mainBundle] bundlePath];
    return strdup([str UTF8String]);
}

