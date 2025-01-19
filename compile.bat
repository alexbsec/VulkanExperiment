@echo off
set GLSLC="X:\path\to\VulkanSDK\x.x.x\Bin31\glslc.exe"

%GLSLC% shaders\simple_shader.vert -o shaders\simple_shader.vert.spv
%GLSLC% shaders\simple_shader.frag -o shaders\simple_shader.frag.spv
pause
