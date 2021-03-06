/************************************************************
ビルトイン関数(一部)
	http://qiita.com/edo_m18/items/71f6064f3355be7e4f45
************************************************************/
#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

#define num (10)
uniform float val_0[num];
uniform float val_1[num];

/************************************************************
************************************************************/
void main() {
	vec3 color = vec3(0.0);
	
	vec4 blue = vec4(0.0, 0.0, 1.0, 1.0);
	vec4 red = vec4(1.0, 0.0, 0.0, 1.0);
	
	int ok = 0;
	for(int i = 0; i < num; i++){
		if(val_0[i] == i)		ok++;
		if(val_1[i] == 10 + i)	ok++;
	}
	if(2 * num <= ok)	gl_FragColor = blue;
	else				gl_FragColor = red;
}
