#ifndef FLIGHTM600_HPP
#define FLIGHTM600_HPP
#include <iostream>
#include "eNumCollections.h"
#include "./different_api/m600/gps/gps.h"
#include "./different_api/m600/navigation/navigation.h"
#include "./different_api/m600/sensor_data/sensor_data.h"
#include "./different_api/m600/status/status.h"

#include "Flights.h"
#include <nlab/math.hpp>
#include <vector>


class FlightM600 :public Flights
{
    public:
    FlightM600() {};
    ~FlightM600() {};
    
    M600Gps *m600gps;
    M600Navigation *m600navigation;
    M600Status *m600status;
    M600SensorData *m600sensordata;
    

    void SetGPSNum()
    {
        Flights::GPSNum_ = m600gps->GetGpsNum();
    }

    void SetGPSHealth()
    {
        Flights::GPShealth_ = static_cast<GPS_HEALTH>(m600gps->GetGpsHealth());
    }
    void SetPositionNED()
    {
        Flights::positionNED_ = m600navigation->GetPosNed();
    }
    void SetPositionLLH()
    {
        Flights::positionLLH_ = m600navigation->GetPosLlh();
    }
    void SetVelocity()
    {
        Flights::velocity_ = m600navigation->GetVelBody(); // Need to change Heading frame  
    }
    void SetAttitude()
    {
        Flights::attitude_ = m600navigation->GetEuler();
    }


    void SetFlightStatus()
    {
        Flights::flightstatus_ = static_cast<FLIGHT_STATUS>(m600status->GetFlightStatus());
    }
    void SetGimbalStatus()
    {
        Flights::gimbalstatus_ = static_cast<PAYLOAD_STATUS>(m600status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::GIMBAL));
    }
    void SetCameraStatus()
    {
        Flights::camerastatus_ = static_cast<PAYLOAD_STATUS>(m600status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::CAMERA));
    }
    void SetDistanceStatus() 
    {
        Flights::distancestatus_ = PAYLOAD_STATUS(DEFAULT);
    }


    void SetCameraData()
    {
        Flights::cameradata_ = m600sensordata->GetCameraData();
    }
    void SetGimbalData()
    {
        Flights::gimbaldata_ = m600sensordata->GetGimbalData();
    }
    void SetDistanceData()
    {
        Flights::distancedata_ = 0;
    }

};

#endif //FLIGHTM600_HPP
