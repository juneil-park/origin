cmake_minimum_required(VERSION 3.16)

project(MC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ### for running
# set(MC_src
#     MissionComputer.cpp
# )

# add_executable(MC_src 
#     MissionComputer.cpp
# )
# ###

#### for gtest

set(MC_src
    MissionComputerTest.cpp
)

add_executable(MC_src 
  MissionComputerTest.cpp
)

enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include)

include(GoogleTest)
gtest_discover_tests(MC_src)
#### 

set(CMAKE_BUILD_TYPE Debug)
set(M300_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/m300)
set(M600_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/m600)
set(MAVIC_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/mavic)
set(SKYDIO_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/different_api/skydio)


add_library(mission_computer SHARED
  ${MC_src}
)

include_directories(mission_computer
	${PROJECT_SOURCE_DIR}
  /usr/local/include/M300_API
  /usr/local/include/M600_API
  /usr/local/include/MAVIC_API
  /usr/local/include/SKYDIO_API
  ) #.h 들이 있는곳

link_directories(/usr/local/lib) #.so file 이 있는곳



target_link_libraries(MC_src 
  dji_m300_api
  dji_m600_api
  dji_mavic_api
  skydio_api
  gtest  
)

# Installation
file(GLOB MC_HEADERS
    Flights.h
    FlightM300.h
    FlightM600.h 
    FlightMavic.h
    FlightSkydio.h
    FcInputlmpl.h
    eNumCollections.h
)

set_target_properties(mission_computer PROPERTIES
        PUBLIC_HEADER "${MC_HEADERS}")

install(TARGETS mission_computer DESTINATION lib
        PERMISSIONS WORLD_EXECUTE WORLD_READ WORLD_WRITE GROUP_EXECUTE GROUP_READ GROUP_WRITE OWNER_EXECUTE OWNER_WRITE OWNER_READ
        PUBLIC_HEADER           DESTINATION include/MC)
        


