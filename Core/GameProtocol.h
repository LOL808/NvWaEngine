//
//  GameProtocol.hpp
//  NvwaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//

#ifndef _NVWA_ENGINE_CORE_GAMEPROTOCOL_
#define _NVWA_ENGINE_CORE_GAMEPROTOCOL_

class GameProtocol {
public:
    enum TargetPlatform {
        OS_iOS,
        OS_COUNT
    };

    virtual ~GameProtocol() {

    }


public:
    virtual bool gameDidFinishLaunching() = 0;

    virtual void gameDidEnterBackground() = 0;

    virtual void gameWillEnterForeground() = 0;


};

#endif /* _NVWA_ENGINE_CORE_GAMEPROTOCOL_ */
