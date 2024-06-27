@echo off
setlocal enabledelayedexpansion

set vs_prefix="vs_"
set fs_prefix="fs_"
set cs_prefix="cs_"
set platform="--platform windows"
set vs_dx_flags=-p s_5_0 -O 3
set fs_dx_flags=-p s_5_0 -O 3
set cs_dx_flags=-p s_5_0 -O 1
set vs_gl_flags=-p 430
set fs_gl_flags=-p 430
set cs_gl_flags=-p 430
set vs_spirv_flags=-p spirv
set fs_spirv_flags=-p spirv
set cs_spirv_flags=-p spirv
set dx_shader_path=..\build\shaders\dx11
set gl_shader_path=..\build\shaders\glsl
set spirv_shader_path=..\build\shaders\spirv
set shdc=..\tools\shadercRelease.exe

if not exist %dx_shader_path% mkdir %dx_shader_path%
if not exist %gl_shader_path% mkdir %gl_shader_path%
if not exist %spirv_shader_path% mkdir %spirv_shader_path%

echo Compiling shaders...
for %%f in (vs_*.sc) do (
  set fullval=%%~nf
  echo !fullval!
  set substr=!fullval:~3!
  @REM echo !substr!
  call %shdc% %platform% %vs_dx_flags% --type vertex --depends --varyingdef !substr!.def.sc -o %dx_shader_path%/%%~nf.bin -f %%f
  call %shdc% %platform% %vs_gl_flags% --type vertex --depends --varyingdef !substr!.def.sc -o %gl_shader_path%/%%~nf.bin -f %%f
  call %shdc% %platform% %vs_spirv_flags% --type vertex --depends --varyingdef !substr!.def.sc -o %spirv_shader_path%/%%~nf.bin -f %%f
)
for %%f in (fs_*.sc) do (
  set fullval=%%~nf
  echo !fullval!
  set substr=!fullval:~3!
  call %shdc% %platform% %vs_dx_flags% --type fragment --depends --varyingdef !substr!.def.sc -o %dx_shader_path%/%%~nf.bin -f %%f
  call %shdc% %platform% %vs_gl_flags% --type fragment --depends --varyingdef !substr!.def.sc -o %gl_shader_path%/%%~nf.bin -f %%f
  call %shdc% %platform% %vs_spirv_flags% --type fragment --depends --varyingdef !substr!.def.sc -o %spirv_shader_path%/%%~nf.bin -f %%f
)
for %%f in (cs_*.sc) do (
  set fullval=%%~nf
  echo !fullval!
  set substr=!fullval:~3!
  call %shdc% %platform% %vs_dx_flags% --type compute --depends -o %dx_shader_path%/%%~nf.bin -f %%f
  call %shdc% %platform% %vs_gl_flags% --type compute --depends -o %gl_shader_path%/%%~nf.bin -f %%f
  call %shdc% %platform% %vs_spirv_flags% --type compute --depends -o %spirv_shader_path%/%%~nf.bin -f %%f
)