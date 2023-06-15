cmake_minimum_required(VERSION 3.10)
project(RenderEngine)

# Set the output directory for the static library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(include)

# List all the source files
set(SOURCES
    src/element/Element.cpp
    src/element/Box.cpp
    src/element/ImageView.cpp
    src/element/TextView.cpp
    src/element/LabelText.cpp
    src/element/TextArea.cpp
    src/element/TextInput.cpp
    src/element/Button.cpp
    src/util/util.cpp
    src/render.cpp
)

# Create the static library
add_library(RenderEngine STATIC ${SOURCES})

# Set the library name
set_target_properties(RenderEngine PROPERTIES OUTPUT_NAME reng)

# Find SFML library
# find_package(SFML REQUIRED COMPONENTS system window graphics)

# # Check if SFML is found
# if (SFML_FOUND)
#     # Include SFML directories
#     include_directories(${SFML_INCLUDE_DIR})
#     # Link SFML libraries
#     target_link_libraries(RenderEngine PRIVATE sfml-system sfml-window sfml-graphics)
# else ()
#     message(FATAL_ERROR "SFML library not found. Please install SFML.")
# endif ()

# Add any additional dependencies and checks as needed

# Example: Find and check for another library
# find_package(AnotherLibrary REQUIRED)
# if (AnotherLibrary_FOUND)
#     include_directories(${AnotherLibrary_INCLUDE_DIRS})
#     target_link_libraries(RenderEngine PRIVATE ${AnotherLibrary_LIBRARIES})
# else ()
#     message(FATAL_ERROR "AnotherLibrary not found. Please install AnotherLibrary.")
# endif ()
