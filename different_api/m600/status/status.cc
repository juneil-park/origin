//
// Created by jhbai on 23. 05. 08.
//

#include "status/status.h"
#include <cstdlib>
#include <time.h>
#include <stdexcept>

M600Status::M600Status() {}
M600Status::~M600Status() {}

M600Status::FLIGHT_STATUS M600Status::GetFlightStatus() {
    srand(time(0));
    return FLIGHT_STATUS(rand() % 4 + 1);
}

M600Status::PAYLOAD_STATUS M600Status::GetPayloadStatus(PAYLOAD_TYPE payload_type) {
    switch (payload_type) {
        case PAYLOAD_TYPE::CAMERA:
            srand(time(0));
            return PAYLOAD_STATUS(rand() % 3);
        case PAYLOAD_TYPE::GIMBAL:
            srand(time(0));
            return PAYLOAD_STATUS(rand() % 3);
        case PAYLOAD_TYPE::SONAR:
            srand(time(0));
            return PAYLOAD_STATUS(rand() % 3);
        default:
            std::string errorMessage = "Wrong payload type, or payload type not specified";
            throw std::runtime_error(errorMessage);
            break;
    }    
}