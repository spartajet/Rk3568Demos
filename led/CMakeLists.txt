project(led)

add_executable(led main.cpp
        main.cpp)

target_link_libraries(led
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)