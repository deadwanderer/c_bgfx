#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

local bgfx_shader_handle_t load_shader(const char* shader_name);

local bgfx_program_handle_t load_program(const char* shader_base_name);

#endif