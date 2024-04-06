include_directories(${CMAKE_SOURCE_DIR}/status)

add_library(sq_list_lib 
    sq_list.cc 
    sq_list.h
    union.cc
    union.h
    merge.cc
    merge.h)

add_executable(sq_list sq_list_main.cc)
target_link_libraries(sq_list sq_list_lib)

add_executable(sq_list_union union_main.cc)
target_link_libraries(sq_list_union sq_list_lib)

add_executable(sq_list_merge merge_main.cc)
target_link_libraries(sq_list_merge sq_list_lib)