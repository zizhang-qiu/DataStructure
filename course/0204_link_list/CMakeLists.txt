include_directories(${CMAKE_SOURCE_DIR}/status)

add_library(link_list_lib
    link_list.cc
    link_list.h
    merge.cc
    merge.h)

add_executable(link_list_main main.cc)
target_link_libraries(link_list_main PUBLIC link_list_lib)

add_executable(link_list_merge merge_main.cc)
target_link_libraries(link_list_merge PUBLIC link_list_lib)