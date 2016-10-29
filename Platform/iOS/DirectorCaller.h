//
//  DirectorCaller.hpp
//  NvWaEngine
//
//  Created by /help on 10/26/16.
//  Copyright © 2016 /help. All rights reserved.
//

//#ifndef DirectorCaller_hpp
//#define DirectorCaller_hpp

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface DirectorCaller : NSObject {
    id displayLink;
    int interval;
    BOOL isGameActived;
}

-(void) startMainLoop;
-(void) stopMainLoop;
-(void) setAnimationInterval:(double) interval;

+(id) getInstance;
+(void) purge;

@end

//#endif /* DirectorCaller_hpp */
