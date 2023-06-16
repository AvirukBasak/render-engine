cmake_minimum_required(VERSION 3.10)
project(RenderEngine)

# Set the output directory for the static library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(include)

# List all the source files
set(SOURCES
    src/element/config/Attributes.cpp
    src/element/Element.cpp
    src/element/Box.cpp
    src/element/ImageView.cpp
    src/element/TextView.cpp
    src/element/LabelText.cpp
    src/element/TextArea.cpp
    src/element/TextInput.cpp
    src/element/Button.cpp
    src/util/util.cpp
    src/reng.cpp
)

# Create the static library
add_library(RenderEngine STATIC ${SOURCES})

# Set the library name
set_target_properties(RenderEngine PROPERTIES OUTPUT_NAME reng)

# SFML library path
if (WIN32)
    set(SFML_ROOT "C:/SFML")
elseif (APPLE)
    set(SFML_ROOT "/usr/local/Cellar/sfml")
elseif (UNIX AND NOT APPLE)
    set(SFML_ROOT "/usr/lib/x86_64-linux-gnu")
else()
    message(FATAL_ERROR "Unsupported operating system. Please manually set the SFML_ROOT variable.")
endif()

# Add SFML installation prefix
set(CMAKE_PREFIX_PATH ${SFML_ROOT} ${CMAKE_PREFIX_PATH})

# Find SFML library
# find_package(SFML 2.4 COMPONENTS system window graphics REQUIRED)

# # Link against SFML libraries
# target_link_libraries(RenderEngine PUBLIC sfml-system sfml-window sfml-graphics)

# Link SFML libraries
target_link_libraries(RenderEngine PUBLIC
    ${SFML_ROOT}/libsfml-system.so
    ${SFML_ROOT}/libsfml-window.so
    ${SFML_ROOT}/libsfml-graphics.so
)

# Add any additional dependencies and checks as needed

# Example: Find and check for another library
# find_package(AnotherLibrary REQUIRED)
# if (AnotherLibrary_FOUND)
#     include_directories(${AnotherLibrary_INCLUDE_DIRS})
#     target_link_libraries(RenderEngine PRIVATE ${AnotherLibrary_LIBRARIES})
# else ()
#     message(FATAL_ERROR "AnotherLibrary not found. Please install AnotherLibrary.")
# endif ()
