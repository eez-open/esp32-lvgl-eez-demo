# idf_component_register(SRCS main.c)

file(GLOB_RECURSE SOURCES_C *.c
                            ./lv_port/*.c
                            lvgl/**/*.cpp
                            lvgl/demos/**/*.c
                            lvgl/demos/**/*.cpp
                            )
file(GLOB_RECURSE SOURCES_CPP *.cpp)

idf_component_register(
    SRCS ${SOURCES_C} ${SOURCES_CPP}
    INCLUDE_DIRS    "."
                    ./lv_port
    REQUIRES        lvgl
                    lvgl_esp32_drivers
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I../components/lvgl/demos/eez")
