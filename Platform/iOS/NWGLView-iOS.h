//
//  NWGLView.h
//  NvWaTest
//
//  Created by /help on 10/24/16.
//  Copyright © 2016 /help. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <QuartzCore/QuartzCore.h>

@interface NWGLView_iOS : UIView
{
    CAEAGLLayer* _eaglLayer;
    EAGLContext* _context;

    GLuint  _colorRenderBuffer;
    GLuint _posSlot;
    GLuint _colorSlot;

}

- (void)setRenderBuffer:(GLuint) buffer;
- (id) initWithFrame:(CGRect)frame;

@end
