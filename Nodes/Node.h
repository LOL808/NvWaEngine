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
#include "../Math/NWMatMath.h"
#include "../Rendering/NWGLProgram.h"



class Node {
public:
    static Node* create();
    static Node* createWithSize(NWSize size);


    virtual void draw();

    void setPosition(const NWVector2& vec);
    void setRotation(float degree);

    float getRotation() {return _rataion;}
//    void setRotationY()

protected:

    Node();
    virtual ~Node();

    NWMat4          _modelView;
    NWGLProgram*    _glProgarm;
    GLuint          _vertexBuffer;
    NWBaiscVertex   _verties[4];

    NWSize          _nodeSize;
    NWPoint         _origin;

    bool            _isModelViewDirty;
    bool            _isVertextDirty;

    float           _rataion;

};

#endif /* Node_hpp */
