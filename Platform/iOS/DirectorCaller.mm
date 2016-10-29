//
//  DirectorCaller.cpp
//  NvWaEngine
//
//  Created by /help on 10/26/16.
//  Copyright © 2016 /help. All rights reserved.
//

#include "DirectorCaller.h"
#include "Director.h"
#include <OpenGLES/EAGL.h>
#include "GLViewImpl-iOS.h"

static id s_sharedDirectorCaller;

@implementation DirectorCaller
+(id) getInstance {
    if (nil == s_sharedDirectorCaller) {
        s_sharedDirectorCaller = [DirectorCaller new];
    }
    return s_sharedDirectorCaller;
}

-(instancetype) init {
    self = [super init];

    if (self) {
//        isGameActived =
        isGameActived = [UIApplication sharedApplication].applicationState == UIApplicationStateActive;
        NSNotificationCenter* nc = [NSNotificationCenter defaultCenter];
        [nc addObserver:self selector:@selector(gameActived) name:UIApplicationDidBecomeActiveNotification object:nil];
        [nc addObserver:self selector:@selector(gameDeActived) name:UIApplicationWillResignActiveNotification object:nil];
    }

    return self;
}

-(void) alloc {
    interval = 1;
}

+(void) purge {
    [s_sharedDirectorCaller stopMainLoop];
    [s_sharedDirectorCaller release];
    s_sharedDirectorCaller = nil;
}

-(void) gameActived {
    isGameActived = YES;
}

-(void) gameDeActived {
    isGameActived = NO;
}

-(void) startMainLoop {
    [self stopMainLoop];
    displayLink = [NSClassFromString(@"CADisplayLink") displayLinkWithTarget:self selector:@selector(doCaller:)];
    [displayLink setFrameInterval:interval];
//    [displayLink ]
    [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}


-(void) stopMainLoop {
//    [displayLink ]
    [displayLink invalidate];
    displayLink = nil;
}

-(void) doCaller:(id) sender {
    if (isGameActived) {
        Director* director = Director::getInstance();
        director->mainLoop();
    }
}

@end

