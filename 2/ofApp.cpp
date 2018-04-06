/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle( "shader test" );
	ofSetWindowShape( WIDTH, HEIGHT );
	
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	shader.load( "shader.vert", "shader.frag" );
	
	/********************
	********************/
	for(int i = 0; i < NUM; i++){
		val_0[i] = i;
		val_1[i] = 10 + i;
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0, 0);
	// ofBackground(255);
	
	shader.begin();
	
		ofSetColor(255, 255, 255, 255);
		
		ofEnableAlphaBlending();
		// ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		
		
		/********************
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
		********************/
#ifdef BUG_FIX
		GLuint program = shader.getProgram();
		glUseProgram(program);
		
		GLint loc = glGetUniformLocation(program, "val_0");
		glUniform1fv(loc, NUM, val_0);
		
		loc = glGetUniformLocation(program, "val_1");
		glUniform1fv(loc, NUM, val_1);
#else
		shader.setUniform1fv("val", val, NUM);
#endif
		
		/********************
		********************/
		ofFill();
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
