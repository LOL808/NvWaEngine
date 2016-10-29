//
//  Node.hpp
//  NvWaEngine
//
//  Created by /help on 10/27/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

//#include "../Math/NWTypes.h"
#include <stdlib.h>
#include "../Math/NWMath.h"
#include "../Rendering/NWGLProgram.h"


class Node {
public:
    static Node* create();
    static Node* createWithSize(NWSize size);
    virtual void draw();

protected:

    Node();
    virtual ~Node();

    NWGLProgram* _glProgarm;
    NWSize      _nodeSize;
};

#endif /* Node_hpp */
