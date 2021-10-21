cmake_minimum_required(VERSION 3.9)

list(APPEND Country au)
list(APPEND LDM_Version 7.2.2 7.2.4)
list(APPEND DDS_Vendor RTI VORTEX)
list(APPEND Build_Type Debug Release)

project(lib LANGUAGES CXX)

if (NOT ${PROJECT_NAME}-MultiBuild)
  set(${PROJECT_NAME}-MultiBuild ON)

  macro (setup_library country build_version dds_vendor build_type )
    add_definitions(-D${dds_vendor})
    set(LIBNAME ${country}.${build_version}.${dds_vendor}.${build_type})
    #    set(LIBNAME MAINLIB)
    set(CMAKE_BUILD_TYPE ${build_type})

    set(BUILD_DIRECTORY_NAME bin.${country}.${build_version}.${dds_vendor}.${build_type})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${BUILD_DIRECTORY_NAME})

    add_subdirectory(
     ${CMAKE_CURRENT_SOURCE_DIR}
     ${CMAKE_SOURCE_DIR}/${BUILD_DIRECTORY_NAME}
    )
    return()
  endmacro()

  foreach(country IN LISTS Country)
    foreach(version IN LISTS LDM_Version)
      foreach(vendor IN LISTS DDS_Vendor)
        foreach(type IN LISTS Build_Type)
    	  setup_library(${country} ${version} ${vendor} ${type}) 
        endforeach()
      endforeach()
   endforeach()
  endforeach()

endif()

include_directories(7.2.2)
add_subdirectory(7.2.2)

add_executable(${LIBNAME} main.cpp)
