#ifndef FCINPUTIMPL_HPP
#define FCINPUTIMPL_HPP
#include <iostream>
#include "Flights.h"
#include "FlightM300.h"
#include "FlightM600.h"

class FCInputImpl
{
    public:
    FCInputImpl() {};
    virtual ~FCInputImpl() {};
    virtual Flights* CreateFlight() = 0 ; 

    Flights* DataExtractApiToMC()
    {
        Flights* flight = CreateFlight();

        ///Extract to Navigation
        flight -> SetGPSNum();
        flight -> SetGPSHealth();
        flight -> SetPositionNED();
        flight -> SetPositionLLH();
        flight -> SetVelocity();
        flight -> SetAttitude();

        ///Extract to Status
        flight -> SetFlightStatus();
        flight -> SetGimbalStatus();
        flight -> SetCameraStatus();
        flight -> SetDistanceStatus();

        // ///Extract to Payload
        // flight -> SetCameraData();
        // flight -> SetGimbalData();
        // flight -> SetDistanceData();

        return flight;
    };


};

class FcInputM300 : public FCInputImpl
{
    public:
    FcInputM300() {};
    ~FcInputM300() {};
    
    Flights* CreateFlight()
    {
        return new FlightM300();
    }

};

class FcInputM600 : public FCInputImpl
{
    public:
    FcInputM600() {};
    ~FcInputM600() {};
    
    Flights* CreateFlight()
    {
        return new FlightM600();
    }

};

#endif //FCINPUTIMPL_HPP

