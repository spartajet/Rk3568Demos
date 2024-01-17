cmake_minimum_required(VERSION 3.16)
project(Rk3568Demos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")
    find_package(Qt5 COMPONENTS
            Core
            Gui
            Widgets
            REQUIRED)
else ()
    set(CMAKE_PREFIX_PATH  "/opt/atk-dlrk356x-toolchain/aarch64-buildroot-linux-gnu/sysroot/usr/lib/cmake/")
    find_package(Qt5 COMPONENTS
            Core
            Gui
            Widgets
            REQUIRED
            PATHS "/opt/atk-dlrk356x-toolchain/aarch64-buildroot-linux-gnu/sysroot/usr/lib/")
endif ()



add_subdirectory(led)
add_subdirectory(key)
#add_executable(Rk3568Demos
#        main.cpp)

#target_link_libraries(led
#        Qt5::Core
#        Qt5::Gui
#        Qt5::Widgets)



