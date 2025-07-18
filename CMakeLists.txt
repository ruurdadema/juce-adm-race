cmake_minimum_required(VERSION 3.31)

include(FetchContent)

project(juce_audio_device_manager_data_race VERSION 1.1.1)

set(CMAKE_CXX_STANDARD 17)

########
# JUCE #
########

FetchContent_Declare(
        JUCE
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG develop
)

set(JUCE_ENABLE_MODULE_SOURCE_GROUPS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS YES)

FetchContent_MakeAvailable(JUCE)

juce_add_console_app(ConsoleAppExample
        PRODUCT_NAME "Console App Example")

target_sources(ConsoleAppExample
        PRIVATE
        main.cpp)

target_compile_definitions(ConsoleAppExample
        PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)

target_link_libraries(ConsoleAppExample
        PRIVATE
        # ConsoleAppData            # If you'd created a binary data target, you'd link to it here
        juce::juce_core
        juce::juce_audio_devices
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_options(ConsoleAppExample PUBLIC -fsanitize=thread -g)
target_link_libraries(ConsoleAppExample PUBLIC -fsanitize=thread)
