cmake_minimum_required(VERSION 3.16)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 14)
add_executable(ProgressBar main.cpp Observer.cpp Subject.cpp ProgressBar.cpp ProgressBar.h Loader.cpp Loader.h)

SET(wxWidgets_ROOT_DIR "C:/wxWidgets-3.1.1")

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(ProgressBar ${wxWidgets_LIBRARIES})
