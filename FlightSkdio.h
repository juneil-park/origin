#ifndef FLIGHTSKYDIO_HPP
#define FLIGHTSKYDIO_HPP
#include <iostream>
#include "eNumCollections.h"

#include "./different_api/skydio/gps/gps.h"
#include "./different_api/skydio/flight_controller/flight_controller.h"
#include "./different_api/skydio/gimbal/gimbal.h"
#include "./different_api/skydio/lidar/lidar.h"
#include "./different_api/skydio/camera/camera.h"

#include "Flights.h"
#include <nlab/math.hpp>
#include <vector>

class FlightSkydio :public Flights
{
    public:
    FlightSkydio() {};
    ~FlightSkydio() {};
    
    SkydioGps *skydiogps;
    SkydioLidar *skydiolidar;
    SkydioGimbal *skydiogimbal;
    SkydioCamera *skydiocamera;
    SkydioFlightController *skydioflightcontroller;

    void SetGPSNum()
    {
        Flights::GPSNum_ = skydiogps->GetGpsNum();
    }

    void SetGPSHealth()
    {
        Flights::GPSHealth_ = static_cast<GPS_HEALTH>(skydiogps->GetGpsHealth());
    }
    void SetPositionNED()
    {
        nlab::lib::Vector3f positionNED_yd = skydioflightcontroller->GetPosNed();
        Flights::positionNED_ = nlab::lib::Vector3f(positionNED_yd(0)*0.9144f,positionNED_yd(1)*0.9144f,positionNED_yd(2)*0.9144f);
    }
    void SetPositionLLH()
    {   
        nlab::lib::Vector3 positionLLH_yd = skydioflightcontroller->GetPosLlh();
        Flights::positionLLH_ = nlab::lib::Vector3((float)positionLLH_yd(0),positionLLH_yd(1),positionLLH_yd(2)*0.9144f);
    }
    void SetVelocity()
    {
        nlab::lib::Vector3f velocity_yd = skydioflightcontroller->GetVelHdg();
        Flights::velocity_ = nlab::lib::Vector3f(velocity_yd(0)*0.9144f,velocity_yd(1)*0.9144f,velocity_yd(2)*0.9144f);
    }
    void SetAttitude()
    {
        nlab::lib::Quaternionf attitude_quat = skydioflightcontroller->GetQuaternion();
        Flights::attitude_ = nlab::lib::Eulerf(attitude_quat);
    }


    void SetFlightStatus()
    {
        Flights::flightstatus_ = static_cast<FLIGHT_STATUS>(skydioflightcontroller->GetFlightStatus());
    }
    void SetGimbalStatus()
    {
        Flights::gimbalstatus_ = static_cast<PAYLOAD_STATUS>(skydiogimbal->GetGimbalStatus());
    }
    void SetCameraStatus()
    {
        Flights::camerastatus_ = static_cast<PAYLOAD_STATUS>(skydiocamera->GetCameraStatus());
    }
    void SetDistanceStatus() 
    {
        Flights::distancestatus_ = static_cast<PAYLOAD_STATUS>(skydiolidar->GetLidarStatus());
    }


    void SetCameraData()
    {
        Flights::cameradata_ = skydiocamera->GetCameraData();
    }
    void SetGimbalData()
    {
        Flights::gimbaldata_ = skydiogimbal->GetGimbalData();
    }
    void SetDistanceData()
    {
        Flights::distancedata_ = skydiolidar->GetForwardLidarDistance();
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