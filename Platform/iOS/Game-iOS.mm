//
//  Game.cpp
//  NvwaEngine
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include <assert.h>
#include "Game.h"
#import "DirectorCaller.h"

Game::Game(){
    assert(m_instance==nullptr);
    m_instance = this;
}
//
Game::~Game(){
    assert(this==m_instance);
    m_instance = 0;
}

Game* Game::m_instance = nullptr;

Game* Game::getInstace() {
    return m_instance;
}

int Game::run() {
    //    gameDidFinishLaunching();
    [[DirectorCaller getInstance] startMainLoop];
    return 0;
}