cmake_minimum_required(VERSION 3.16)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 14)
add_executable(ProgressBar ProgressBar.cpp ProgressBar.h Observer.h Observer.cpp Subject.h Subject.cpp  Loader.cpp Loader.h)

find_package(wxWidgets 3.1.4 COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(ProgressBar ${wxWidgets_LIBRARIES})
