# idf_component_register(SRCS main.c)

file(GLOB_RECURSE SOURCES_C *.c
                            ./lv_port/*.c
                            ./ui/*.c
                            ../components/eez-framework/src/eez/**/*.cpp
                            ../components/eez-framework/src/eez/**/*.c
                            lvgl/**/*.cpp
                            lvgl/demos/**/*.c
                            lvgl/demos/**/*.cpp
                            )
file(GLOB_RECURSE SOURCES_CPP *.cpp)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DEEZ_PLATFORM_ESP32 -DEEZ_FOR_LVGL")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEEZ_PLATFORM_ESP32 -DEEZ_FOR_LVGL")

idf_component_register(
    SRCS ${SOURCES_C} ${SOURCES_CPP}
    INCLUDE_DIRS    "."
                    ../components/eez-framework/src
                    ../components/eez-framework/src/eez/libs/agg 
                    ../components/eez-framework/src/eez/platform/simulator 
                    ./lv_port
    REQUIRES        lvgl
                    lvgl_esp32_drivers
    )
