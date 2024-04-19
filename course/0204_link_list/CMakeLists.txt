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

add_library(s_link_list_lib
    s_link_list.cc
    s_link_list.h
    difference.cc
    difference.h)

add_executable(s_link_list_main s_link_list_main.cc)
target_link_libraries(s_link_list_main PUBLIC s_link_list_lib)

add_executable(s_link_list_difference difference_main.cc)
target_link_libraries(s_link_list_difference PUBLIC s_link_list_lib)
