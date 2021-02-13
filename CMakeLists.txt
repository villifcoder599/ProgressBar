cmake_minimum_required(VERSION 3.16)
project(ProgressBar)
add_subdirectory(./test)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES  ProgressBar.cpp LoaderWxApp.cpp  LoaderWxMain.cpp  ManagerFile.cpp )
add_executable(ProgressBar LoaderWxApp.cpp ProgressBar.cpp ProgressBar.h Observer.h Subject.h LoaderWxApp.cpp LoaderWxApp.h LoaderWxMain.cpp LoaderWxMain.h ManagerFile.cpp ManagerFile.h)
add_library(core  ${SOURCE_FILES})
find_package(wxWidgets 3.1.4 COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(ProgressBar ${wxWidgets_LIBRARIES})
target_link_libraries(ProgressBar core)
