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
        Flights::GPSHealth_ = static_cast<GPS_HEALTH>(mavicgps->GetGpsHealth());
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

    float GetGPSNum() {return Flights::GPSNum_;}
    GPS_HEALTH GetGPSHealth(){return Flights::GPSHealth_;}
    nlab::lib::Vector3f GetPositionNED(){return Flights::positionNED_;}
    nlab::lib::Vector3 GetPositionLLH(){return Flights::positionLLH_;}
    nlab::lib::Vector3f GetVelocity(){return Flights::velocity_;}
    nlab::lib::Vector3f GetAttitude(){return Flights::attitude_;}
    FLIGHT_STATUS GetFlightStatus(){return Flights::flightstatus_;}
    PAYLOAD_STATUS GetGimbalStatus(){return Flights::gimbalstatus_;}
    PAYLOAD_STATUS GetCameraStatus(){return Flights::camerastatus_;}
    PAYLOAD_STATUS GetDistanceStatus(){return Flights::distancestatus_;}
    std::vector<std::vector<int>> GetCameraData(){return Flights::cameradata_;}
    nlab::lib::Vector3f GetGimbalData(){return Flights::gimbaldata_;}
    float GetDistanceData(){return Flights::distancedata_;}

};

#endif //FLIGHTM300_HPP