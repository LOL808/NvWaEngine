//
//  NWGLProgramCache.hpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_RENDERING_NWGLPROGRAMCACHE_
#define _NVWA_ENGINE_RENDERING_NWGLPROGRAMCACHE_

class NWGLProgramCache {
public:
    static NWGLProgramCache* getInstance();

private:

    static NWGLProgramCache* m_instance;
};

#endif /* NWGLProgramCache_hpp */
