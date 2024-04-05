mkdir bin\win32
pushd bin\win32
cl ..\..\src\main.c ..\..\src\main.c ..\..\src\eenheid\e_test.c
popd
bin\win32\main.exe
