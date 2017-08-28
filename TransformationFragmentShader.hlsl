#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexPosition_texture;

out vec2 tex;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(vertexPosition_modelspace, 1.0);
	//gl_Position.w = 1.0;
	tex = vec2(vertexPosition_texture.x, vertexPosition_texture.y);
}
