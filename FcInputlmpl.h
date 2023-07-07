#ifndef FCINPUTIMPL_HPP
#define FCINPUTIMPL_HPP
#include <iostream>
#include "Flights.h"
#include "FlightM300.h"
#include "FlightM600.h"
#include "FlightMavic.h"
#include "FlightSkdio.h"

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

        ///Extract to Payload
        flight -> SetCameraData();
        flight -> SetGimbalData();
        flight -> SetDistanceData();

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

class FcInputMavic : public FCInputImpl
{
    public:
    FcInputMavic() {};
    ~FcInputMavic() {};
    
    Flights* CreateFlight()
    {
        return new FlightMavic();
    }

};

class FcInputSkydio : public FCInputImpl
{
    public:
    FcInputSkydio() {};
    ~FcInputSkydio() {};
    
    Flights* CreateFlight()
    {
        return new FlightSkydio();
    }

};


#endif //FCINPUTIMPL_HPP

