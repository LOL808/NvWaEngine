attribute vec4 Position;
attribute vec4 SourceColor;

uniform mat4 ModelView;
uniform mat4 Projection;
varying vec4 DestColor;

void main(void) {
    DestColor   = SourceColor;
    gl_Position = Projection*ModelView*Position;
}