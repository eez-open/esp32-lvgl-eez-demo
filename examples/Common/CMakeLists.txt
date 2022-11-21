# idf_component_register(SRCS main.c)

file(GLOB_RECURSE SOURCES_C *.c
                            ./lv_port/*.c
                            ./ui/*.c
                            ../components/eez-framework/eez/**/*.cpp
                            ../components/eez-framework/eez/**/*.c
                            lvgl/**/*.cpp
                            lvgl/demos/**/*.c
                            lvgl/demos/**/*.cpp
                            )
file(GLOB_RECURSE SOURCES_CPP *.cpp)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DEEZ_PLATFORM_SIMULATOR -DEEZ_FOR_LVGL -DEEZ_OPTION_GUI=0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEEZ_PLATFORM_SIMULATOR -DEEZ_FOR_LVGL -DEEZ_OPTION_GUI=0")

idf_component_register(
    SRCS ${SOURCES_C} ${SOURCES_CPP}
    INCLUDE_DIRS    "."
                    ../components/eez-framework
                    ../components/eez-framework/eez/libs/agg 
                    ../components/eez-framework/eez/platform/simulator 
                    ../components/eez-framework/conf
                    ./lv_port
    REQUIRES        lvgl
                    lvgl_esp32_drivers
    )
