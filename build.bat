@echo off
setlocal
cd /D "%~dp0"

:: --- Unpack Arguments --------------------------------
for %%a in (%*) do set "%%a=1"
if not "%msvc%"=="1" if not "%clang%"=="1" set msvc=1
if not "%release%"=="1" set debug=1
if "%debug%"=="1" set release=0 && echo [debug mode]
if "%release%"=="1" set debug=0 && echo [release mode]
if "%msvc%"=="1" set clang=0 && set compiler=msvc && echo [msvc compile]
if "%clang%"=="1" set msvc=0 && set compiler=clang && echo [clang compile]
if "%~1"=="" echo [default mode, assuming `main` build] && set main=1


:: --- Compile/Link Line Definitions --------------------
set cl_common= /I..\src\ /I..\third_party\include /nologo /FC /Z7 /MDd
set clang_common= -I..\src\ -I..\third_party\include -gcodeview -fdiagnostics-absolute-paths -Wall -Wno-switch -Wno-unknown-warning-option -Wno-missing-braces -Wno-unused-function -Wno-writable-strings -Wno-unused-value -Wno-unused-variable -Wno-unused-local-typedef -Wno-deprecated-register -Wno-deprecated-declarations -Wno-unused-but-set-variable -Wno-single-bit-bitfield-constant-conversion -Xclang -flto-visibility-public-std -D_USE_MATH_DEFINES -Dstrdup=_strdup -Dgnu_printf=printf
set cl_debug= call cl /Od /DBUILD_DEBUG=1 %cl_common%
set cl_release= call cl /O2 /DBUILD_DEBUG=0 %cl_common%
set clang_debug= call clang -g -O0 -DBUILD_DEBUG=1 %clang_common%
set clang_release= call clang -g -O2 -DBUILD_DEBUG=0 %clang_common%
set cl_link= /link /MANIFEST:EMBED /INCREMENTAL:NO /NODEFAULTLIB:libcmtd /LIBPATH:..\third_party\lib shell32.lib user32.lib kernel32.lib winmm.lib gdi32.lib opengl32.lib SDL3.lib 
set clang_link= -fuse-ld=lld -Xlinker /MANIFEST:EMBED -L..\third_party\lib -lshell32 -luser32 -lkernel32 -lwinmm -lgdi32 -lopengl32 -lSDL3
set cl_out= /out:
set clang_out= --output=
set cl_debug_libs=bgfxDebug.lib bimgDebug.lib bxDebug.lib
set cl_release_libs=bgfxRelease.lib bimgRelease.lib bxRelease.lib
set clang_debug_libs=-lbgfxDebug -lbimgDebug -lbxDebug
set clang_release_libs=-lbgfxRelease -lbimgRelease -lbxRelease
:: --- Choose Compile/Link Lines -------------------------
if "%msvc%"=="1" set compile_debug=%cl_debug%
if "%msvc%"=="1" set compile_release=%cl_release%
if "%msvc%"=="1" set compile_link=%cl_link%
if "%msvc%"=="1" set out=%cl_out%app.exe
if "%msvc%"=="1" set debug_libs=%cl_debug_libs%
if "%msvc%"=="1" set release_libs=%cl_release_libs%
if "%clang%"=="1" set compile_debug=%clang_debug%
if "%clang%"=="1" set compile_release=%clang_release%
if "%clang%"=="1" set compile_link=%clang_link%
if "%clang%"=="1" set out=%clang_out%app.exe
if "%clang%"=="1" set debug_libs=%clang_debug_libs%
if "%clang%"=="1" set release_libs=%clang_release_libs%
if "%debug%"=="1" set compile=%compile_debug%
if "%debug%"=="1" set libs=%debug_libs%
if "%release%"=="1" set compile=%compile_release%
if "%release%"=="1" set libs=%release_libs%

:: --- Prep Directories -----------------------------------
if not exist build mkdir build
@REM if not exist local mkdir local

:: --- Get Current Git Commit Id ----------------------------------------------
@REM for /f %%i in ('call git describe --always --dirty') do set compile=%compile% -DBUILD_GIT_HASH=\"%%i\"

pushd build
if "%main%"=="1" %compile% ..\src\main.c %compile_link% %libs% %out% || exit /b 1
popd

:: --- Unset ------------------------------------------------------------------
for %%a in (%*) do set "%%a=0"
set compile=
set compile_link=
set out=
set msvc=
set debug=