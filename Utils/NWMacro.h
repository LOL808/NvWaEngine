//
//  NWMacro.h
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_UTILS_NWMacro_
#define _NVWA_ENGINE_UTILS_NWMacro_

#define BREAK_IF(cond) if((cond)==true) break;

#define RD_CHECK_GL_ERROR() \
do { \
GLenum __error = glGetError(); \
if(__error) { \
printf("[OpenGL Error]: 0x%04X in %s %s %d\n", __error, __FILE__, __FUNCTION__, __LINE__); \
} \
} while (false)

#endif
