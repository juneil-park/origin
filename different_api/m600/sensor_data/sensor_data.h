//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBM600_SENSOR_DATA_HPP
#define LIBM600_SENSOR_DATA_HPP

#include <nlab/math.hpp>

class M600SensorData {
public: 
    M600SensorData();
    ~M600SensorData();
    
    /**
     * @brief Returns image data in 2D vector
     * @return Returns 2D vector
     */
    std::vector<std::vector<int>> GetCameraData();

    /**
     * @brief Returns gimbal roll, pitch, yaw angles
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetGimbalData();
};

#endif  // LIBM600_SENSOR_DATA_HPP