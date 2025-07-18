cmake_minimum_required(VERSION 3.31)

project(juce_audio_device_manager_data_race VERSION 1.1.1)

set(CMAKE_CXX_STANDARD 17)

set(JUCE_ENABLE_MODULE_SOURCE_GROUPS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

add_subdirectory(JUCE)

juce_add_console_app(ConsoleAppExample
        PRODUCT_NAME "Console App Example")

target_sources(ConsoleAppExample
        PRIVATE
        main.cpp)

target_compile_definitions(ConsoleAppExample
        PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)

target_link_libraries(ConsoleAppExample
        PRIVATE
        juce::juce_core
        juce::juce_audio_devices
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_options(ConsoleAppExample PUBLIC -fsanitize=thread -g)
target_link_libraries(ConsoleAppExample PUBLIC -fsanitize=thread)
