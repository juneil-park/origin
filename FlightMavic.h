#ifndef FLIGHTMAVIC_HPP
#define FLIGHTMAVIC_HPP
#include <iostream>
#include "eNumCollections.h"

#include "./different_api/mavic/gps/gps.h"
#include "./different_api/mavic/sensor/sensor.h"
#include "./different_api/mavic/status/status.h"

#include "Flights.h"
#include <nlab/math.hpp>
#include <vector>


class FlightMavic :public Flights
{
    public:
    FlightMavic() {};
    ~FlightMavic() {};
    
    MavicGps *mavicgps;
    MavicCameraData* maviccameradata;
    MavicGimbalData* mavicgimbaldata;
    MavicIntegratedNavigation* mavicintegratednavigation;
    MavicLidarData* maviclidardata;
    MavicVisualData* mavicvisualdata;
    MavicStatus* mavicstatus;

    void SetGPSNum()
    {
        Flights::GPSNum_ = mavicgps->GetGpsNum();
    }

    void SetGPSHealth()
    {
        Flights::GPShealth_ = static_cast<GPS_HEALTH>(mavicgps->GetGpsHealth());
    }
    void SetPositionNED()
    {
        Flights::positionNED_ = mavicintegratednavigation->GetPosNed();
    }
    void SetPositionLLH()
    {
        Flights::positionLLH_ = mavicintegratednavigation->GetPosLlh();
    }
    void SetVelocity()
    {
        Flights::velocity_ = mavicintegratednavigation->GetVelHdg();
    }
    void SetAttitude()
    {
        Flights::attitude_ = mavicintegratednavigation->GetEuler();
    }


    void SetFlightStatus()
    {
        Flights::flightstatus_ = static_cast<FLIGHT_STATUS>(mavicstatus->GetFlightStatus());
    }
    void SetGimbalStatus()
    {
        Flights::gimbalstatus_ = static_cast<PAYLOAD_STATUS>(mavicstatus->GetPayloadStatus(MavicStatus::PAYLOAD_TYPE::GIMBAL));
    }
    void SetCameraStatus()
    {
        Flights::camerastatus_ = static_cast<PAYLOAD_STATUS>(mavicstatus->GetPayloadStatus(MavicStatus::PAYLOAD_TYPE::CAMERA));
    }
    void SetDistanceStatus() 
    {
        Flights::distancestatus_ = static_cast<PAYLOAD_STATUS>(mavicstatus->GetPayloadStatus(MavicStatus::PAYLOAD_TYPE::LIDAR));
    }


    void SetCameraData()
    {
        Flights::cameradata_ = maviccameradata->GetCameraData();
    }
    void SetGimbalData()
    {
        Flights::gimbaldata_ = mavicgimbaldata->GetGimbalData();
    }
    void SetDistanceData()
    {
        Flights::distancedata_ = mavicvisualdata->GetVisualDepth();
    }

};

#endif //FLIGHTM300_HPP