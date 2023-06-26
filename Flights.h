#ifndef FLIGHT_HPP
#define FLIGHT_HPP
#include <iostream>
#include "eNumCollections.h"
#include <nlab/math.hpp>
#include <vector>

class Flights
{
    public:
    Flights(){};
    virtual ~Flights() {};
    
    virtual void SetGPSNum() = 0;
    virtual void SetGPSHealth() = 0;
    virtual void SetPositionNED() = 0;
    virtual void SetPositionLLH() = 0;
    virtual void SetVelocity() = 0;
    virtual void SetAttitude() = 0;

    virtual void SetFlightStatus() = 0;
    virtual void SetGimbalStatus() = 0;
    virtual void SetCameraStatus() = 0;
    virtual void SetDistanceStatus() = 0;

    virtual void SetCameraData() = 0;
    virtual void SetGimbalData() = 0;
    virtual void SetDistanceData() = 0;
    
    void ShowGPSNum()
    {
        std::cout << "GPSNum : " << GPSNum_<<std::endl;
    }

    virtual float GetGPSNum() = 0; 
    virtual GPS_HEALTH GetGPSHealth() = 0;
    virtual nlab::lib::Vector3f GetPositionNED() = 0;
    virtual nlab::lib::Vector3 GetPositionLLH() = 0;
    virtual nlab::lib::Vector3f GetVelocity() = 0;
    virtual nlab::lib::Vector3f GetAttitude() = 0;
    virtual FLIGHT_STATUS GetFlightStatus() = 0;
    virtual PAYLOAD_STATUS GetGimbalStatus() = 0;
    virtual PAYLOAD_STATUS GetCameraStatus() = 0;
    virtual PAYLOAD_STATUS GetDistanceStatus() = 0;
    virtual std::vector<std::vector<int>> GetCameraData() = 0;
    virtual nlab::lib::Vector3f GetGimbalData() = 0;
    virtual float GetDistanceData() = 0;

    protected:
    float GPSNum_;
    GPS_HEALTH GPSHealth_;
    nlab::lib::Vector3f positionNED_;
    nlab::lib::Vector3 positionLLH_;
    nlab::lib::Vector3f velocity_;
    nlab::lib::Vector3f attitude_;
    
    FLIGHT_STATUS flightstatus_ ;
    PAYLOAD_STATUS gimbalstatus_ ;
    PAYLOAD_STATUS camerastatus_ ;
    PAYLOAD_STATUS distancestatus_ ;
    
    std::vector<std::vector<int>> cameradata_;
    nlab::lib::Vector3f gimbaldata_;
    float distancedata_ ;
    

    
};
#endif
