/************************************************************
ビルトイン関数(一部)
	http://qiita.com/edo_m18/items/71f6064f3355be7e4f45
************************************************************/
#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect inputTexture;

#define num (10)
uniform float val[num];

/******************************
******************************/
void main(){
	vec2 texCoord = gl_TexCoord[0].xy;
	
	vec4 color = texture2DRect( inputTexture, texCoord );
	// color.a = 1.0;
	
	vec4 blue = vec4(0.0, 0.0, 1.0, 1.0);
	vec4 red = vec4(1.0, 0.0, 0.0, 1.0);
	
	
	int ok = 0;
	for(int i = 0; i < num; i++){
		if(val[i] == i) ok++;
	}
	if(num <= ok)	gl_FragColor = blue;
	else			gl_FragColor = red;
	// gl_FragColor = color;
}
