//
//  NWGLProgramCache.cpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "NWGLProgramCache.h"

NWGLProgramCache* NWGLProgramCache::m_instance = nullptr;

NWGLProgramCache* NWGLProgramCache::getInstance() {
    if (!m_instance) {
        m_instance = new NWGLProgramCache;
    }
    return m_instance;
}

