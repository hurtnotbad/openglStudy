# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/glm)
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/glm/glm)
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/common)
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/threeeD)
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/twoD)
include_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/twoD/include)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/common/ggl.cpp
             src/main/cpp/opengl.cpp
             src/main/cpp/threeeD/scene2.cpp
             src/main/cpp/common/utils.cpp
             src/main/cpp/common/model.cpp
             src/main/cpp/threeeD/ThreeDCoordinates.cpp
             src/main/cpp/twoD/fbo.cpp
             src/main/cpp/twoD/noFilter.cpp
             src/main/cpp/twoD/drawer.cpp
             src/main/cpp/twoD/grayFilter.cpp
             src/main/cpp/twoD/gaussFilter.cpp



             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )



# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
                        GLESv1_CM
                        GLESv2
                        android
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       )