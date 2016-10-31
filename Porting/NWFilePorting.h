//
//  NWFilePorting-iOS.hpp
//  NvWaEngine
//
//  Created by /help on 10/29/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_PORTING_NWFILEPORTING_H_
#define _NVWA_ENGINE_PORTING_NWFILEPORTING_H_



char* NWFilePorting_getBundlePath();

unsigned char* NWFilePorting_getData(const char* fullPath, bool isText, size_t *outSize);

#endif /* NWFilePorting_iOS_hpp */
