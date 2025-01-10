set(CMAKE_SYSTEM_NAME Windows)

set(CMAKE_CXX_STANDARD_LIBRARIES "-lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 -lstdc++exp -lstdc++fs")
set(CMAKE_CXX_FLAGS "-target x86_64-w64-mingw32 -nostdinc++ -isystem c:/mingw64/include/c++/14.2.0/ -isystem c:/mingw64/include/c++/14.2.0/x86_64-w64-mingw32/")
set(CMAKE_EXE_LINKER_FLAGS "-target x86_64-w64-mingw32")

set(CMAKE_C_COMPILER   clang.exe)
set(CMAKE_CXX_COMPILER clang++.exe)

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH c:/mingw64)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
