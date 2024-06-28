@echo off

set geometryc=..\tools\geometrycRelease.exe
set texturec=..\tools\texturecRelease.exe
set output=..\build\assets

echo Building assets...
pushd assets

for %%f in (meshes\*.obj) do (
  if not exist %output%\meshes\ mkdir %output%\meshes\
  %geometryc% -f %%f -o %output%/meshes/%%~nf.bin --packnormal 1 --barycentric
)
for %%f in (textures\*.*) do (
  if not exist %output%\textures\ mkdir %output%\textures\
  %texturec% -f %%f -o %output%/textures/%%~nf.dds -t bc3 -m
)
popd