#ifndef FLIGHTMAVIC_HPP
#define FLIGHTMAVIC_HPP
#include <iostream>
#include "eNumCollections.h"

#include "./different_api/mavic/gps/gps.cc"
#include "./different_api/mavic/sensor/camera_data/camera_data.cc"
#include "./different_api/mavic/status/status.cc"
#include "Flights.h"
#include <nlab/math.hpp>
#include <vector>


class FlightMavic :public Flights
{
    public:
    FlightMavic() {};
    ~FlightMavic() {};
    
    MavicGps *mavicgps;
    M300Navigation *m300navigation;
    M300Status *m300status;
    M300SensorData *m300sensordata;
    

    void SetGPSNum()
    {
        Flights::GPSNum_ = m300gps->GetGpsNum();
    }

    void SetGPSHealth()
    {
        Flights::GPShealth_ = static_cast<GPS_HEALTH>(m300gps->GetGpsHealth());
    }
    void SetPositionNED()
    {
        Flights::positionNED_ = m300navigation->GetPosNed();
    }
    void SetPositionLLH()
    {
        Flights::positionLLH_ = m300navigation->GetPosLlh();
    }
    void SetVelocity()
    {
        Flights::velocity_ = m300navigation->GetVelHdg();
    }
    void SetAttitude()
    {
        Flights::attitude_ = m300navigation->GetEuler();
    }


    void SetFlightStatus()
    {
        Flights::flightstatus_ = static_cast<FLIGHT_STATUS>(m300status->GetFlightStatus());
    }
    void SetGimbalStatus()
    {
        Flights::gimbalstatus_ = static_cast<PAYLOAD_STATUS>(m300status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::GIMBAL));
    }
    void SetCameraStatus()
    {
        Flights::camerastatus_ = static_cast<PAYLOAD_STATUS>(m300status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::CAMERA));
    }
    void SetDistanceStatus() 
    {
        Flights::distancestatus_ = static_cast<PAYLOAD_STATUS>(m300status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::SONAR));
    }


    void SetCameraData()
    {
        Flights::cameradata_ = m300sensordata->GetCameraData();
    }
    void SetGimbalData()
    {
        Flights::gimbaldata_ = m300sensordata->GetGimbalData();
    }
    void SetDistanceData()
    {
        Flights::distancedata_ = m300sensordata->GetSonarData();
    }

};

#endif //FLIGHTM300_HPP