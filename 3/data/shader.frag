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

/********************
description
	shaderでは、多次元配列を扱えない.
		uniform float val[3][2];
	などはCompile Error.
	
	But, Array of vectorは定義できる.
	float val[][2]
	float val[][3]
	float val[][4]
	までの範囲であれば、vec2 - vec4を使って対応できる。
	実際にはeCPU側で多次元配列を定義し、これを Array of vectorとしてshaderに渡す。
	
keyword
	glUniform2fv, vec2
	glUniform3fv, vec3,
	glUniform4fv, vec4,
	
	glUniform2iv, ivec2,
	glUniform3iv, ivec3,
	glUniform4iv, ivec4,
********************/
uniform vec2 ArrayData[3];
uniform ivec2 i_ArrayData[3];

/************************************************************
************************************************************/
void main() {
	/********************
	********************/
	vec3 color = vec3(0.0);
	
	/********************
	********************/
	if(ArrayData[2][1] == 101.0){
	// if(ArrayData[2].y == 101.0){ // こちらでもAccess OK.
		color = vec3(1.0, 0.0, 0.0);
	}else{
		color = vec3(0.0, 0.0, 1.0);
	}
	
	/********************
	********************/
	/*
	if(i_ArrayData[2][1] == 101){
		color = vec3(1.0, 1.0, 0.0);
	}else{
		color = vec3(0.0, 0.0, 1.0);
	}
	*/
	
	/********************
	********************/
	gl_FragColor = vec4(color, 1.0);
}
