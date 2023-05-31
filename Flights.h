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

    protected:
    float GPSNum_;
    GPS_HEALTH GPShealth_;
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
    

    // void GetGPSNum()
    // void GetGPSHealth()
    // void GetPositionNED()
    // void GetPositionLLH()
    // void GetVelocity()
    // void GetAttitude()
    // void GetFlightStatus()
    // void GetGimbalStatus()
    // void GetCameraStatus()
    // void GetDistanceStatus()
    // void GetCameraData()
    // void GetGimbalData()
    // void GetDistanceData()
};
#endif
