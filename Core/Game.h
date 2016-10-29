//
//  Game.hpp
//  NvwaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_CORE_GAME_
#define _NVWA_ENGINE_CORE_GAME_

#include "GameProtocol.h"

class Game : public GameProtocol {
public:
    static Game* getInstace();
    int run();
protected:
    Game();
    virtual ~Game();

private:
    static Game* m_instance;
};

#endif /* _NVWA_ENGINE_CORE_GAMEPROTOCOL_ */
