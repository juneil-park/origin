#pragma once
enum class GPS_HEALTH {
        NONE = 0,
        OPERATIONAL = 1,
        OPTIMAL = 2
    };

enum class RTK_CONNECTION {
        DISCONNECTED = 0,
        CONNECTED = 1
    };


enum FLIGHT_STATUS {
        DEFAULT = 0,
        ON_GROUND = 1,
        ARMED = 2,
        IN_FLIGHT = 3,
        ERROR = 4
    };


enum class PAYLOAD_STATUS {
    DEFAULT = 0,
    OPERATIONAL = 1,
    ERROR = 2,
};

enum class LIDAR_STATUS {
        DEFAULT = 0,
        OPERATIONAL = 1,
        ERROR = 2,
    };