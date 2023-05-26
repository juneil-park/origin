cmake_minimum_required(VERSION 3.16)

project(MC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MC_src
    MissionComputer.cpp
)

set(CMAKE_BUILD_TYPE Debug)
set(M300_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/m300/)
set(M600_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/m600/)
set(MAVIC_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/mavic/)


set(m300_srcs
${CMAKE_CURRENT_SOURCE_DIR}/different_api/m300/gps/gps.cc
${CMAKE_CURRENT_SOURCE_DIR}/different_api/m300/navigation/navigation.cc
# ${CMAKE_CURRENT_SOURCE_DIR}/different_api/m300/sensor_data/sensor_data.cc
${CMAKE_CURRENT_SOURCE_DIR}/different_api/m300/status/status.cc
)

set(m600_srcs
${CMAKE_CURRENT_SOURCE_DIR}/different_api/m600/gps/gps.cc
${CMAKE_CURRENT_SOURCE_DIR}/different_api/m600/navigation/navigation.cc
# ${CMAKE_CURRENT_SOURCE_DIR}/different_api/m600/sensor_data/sensor_data.cc
${CMAKE_CURRENT_SOURCE_DIR}/different_api/m600/status/status.cc
)

add_library(mission_computer SHARED
  ${MC_src}
  # ${m300_srcs}
  # ${m600_srcs}  
)

include_directories(mission_computer
	${PROJECT_SOURCE_DIR}
)

link_directories(
  ${M300_LIBRARY_DIR}/gps
  ${M300_LIBRARY_DIR}/navigation
  ${M300_LIBRARY_DIR}/status
  ${M600_LIBRARY_DIR}/gps
  ${M600_LIBRARY_DIR}/navigation
  ${M600_LIBRARY_DIR}/status
  ${MAVIC_LIBRARY_DIR}
)

# Installation
file(GLOB MC_HEADERS
    Flights.h
    FlightM300.h
    FlightM600.h 
    FcInputlmpl.h
    eNumCollections.h

    # ${M300_LIBRARY_DIR}/gps/gps.h
    # ${M300_LIBRARY_DIR}/navigation/navigation.h
    # ${M300_LIBRARY_DIR}/status/status.h
    # ${M600_LIBRARY_DIR}/gps/gps.h
    # ${M600_LIBRARY_DIR}/navigation/navigation.h
    # ${M600_LIBRARY_DIR}/status/status.h
)

set_target_properties(mission_computer PROPERTIES
        PUBLIC_HEADER "${MC_HEADERS}")

install(TARGETS mission_computer DESTINATION lib
        PERMISSIONS WORLD_EXECUTE WORLD_READ WORLD_WRITE GROUP_EXECUTE GROUP_READ GROUP_WRITE OWNER_EXECUTE OWNER_WRITE OWNER_READ
        PUBLIC_HEADER           DESTINATION include/MC)
        
add_subdirectory(different_api/m300)
add_subdirectory(different_api/m600)
add_subdirectory(different_api/mavic)