cmake_minimum_required(VERSION 3.16)

project(MAVICAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MAVIC_API_SRCS
  gps/gps.cc
  status/status.cc
)

add_library(dji_mavic_api SHARED
  ${MAVIC_API_SRCS}
)

include_directories(dji_mavic_api
	${PROJECT_SOURCE_DIR}
)

# Installation
file(GLOB MAVIC_API_HEADERS
    gps/gps.h
    sensor/sensor.h
    status/status.h
)

set_target_properties(dji_mavic_api PROPERTIES
        PUBLIC_HEADER "${MAVIC_API_HEADERS}")

install(TARGETS dji_mavic_api DESTINATION lib
        PERMISSIONS WORLD_EXECUTE WORLD_READ WORLD_WRITE GROUP_EXECUTE GROUP_READ GROUP_WRITE OWNER_EXECUTE OWNER_WRITE OWNER_READ
        PUBLIC_HEADER           DESTINATION include/MAVIC_API)
        