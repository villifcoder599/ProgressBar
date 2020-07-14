cmake_minimum_required(VERSION 3.16)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProgressBar main.cpp Observer.cpp Subject.cpp)

SET(wxWidgets_ROOT_DIR "C:/wxWidgets-3.1.1")
SET(wxWidgets_LIB_DIR "C:/wxWidgets-3.1.1/build1/lib/vc_dll")
SET(wxWidgets_LIBRARIES "C:/wxWidgets-3.1.1/lib")
SET(wxWidgets_INCLUDE_DIRS "C:/wxWidgets-3.1.1/include/wx")

set(wxWidgets_INCLUDE_DIRS "C:/wxWidgets-3.1.1")
set(wxWidgets_LIBRARIES "C:/wxWidgets-3.1.1/build1/lib/vc_dll")
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(ProgressBar ${wxWidgets_LIBRARIES})
