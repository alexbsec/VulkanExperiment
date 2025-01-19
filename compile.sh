# Change the path to your glslc SDK path
alias glslc=/usr/bin/glslc

glslc shaders/simple_shader.vert -o shaders/simple_shader.vert.spv
glslc shaders/simple_shader.frag -o shaders/simple_shader.frag.spv
