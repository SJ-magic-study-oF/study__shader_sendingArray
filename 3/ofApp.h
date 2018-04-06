/************************************************************
bug : How to send an array to a shader frag on oF0.9.0
	https://forum.openframeworks.cc/t/how-to-send-an-array-to-a-shader-frag-on-of0-9-0/21516/4
	
	when using the underlying OpenGL commands, it works fine.
	
	{
		...
		
		GLuint program = shader.getProgram();
		GLint loc = glGetUniformLocation(program, "offset");
		glUseProgram(program);
		glUniform1fv(loc, NUM_LINES, offset);
		
		...
	}
	
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
************************************************************/
#define BUG_FIX

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	enum{
		WIDTH = 600,
		HEIGHT = 600,
	};
	
	ofShader shader;
	
	enum{
		NUM = 10,
	};
	float val_0[NUM];
	float val_1[NUM];
	
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
