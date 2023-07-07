#include <iostream>
#include <gtest/gtest.h>
#include "eNumCollections.h"
#include "Flights.h"
#include "FcInputlmpl.h"
#include "FlightM300.h"
#include "FlightM600.h"
#include "FlightMavic.h"


bool GPSHealthTest(Flights *flight)
{   
    GPS_HEALTH gpsHealth_ = flight -> GetGPSHealth();
    if (gpsHealth_ == GPS_HEALTH::OPERATIONAL || gpsHealth_ == GPS_HEALTH::OPTIMAL) {return true;}
    else { return false;}
}


bool FlightStatusTest(Flights *flight)
{   
    if (flight -> GetFlightStatus() == FLIGHT_STATUS::DEFAULT || flight -> GetFlightStatus() == FLIGHT_STATUS::ERROR) {return false;}
    else { return true;}
}


bool GimbalStatusTest(Flights *flight)
{   
    if (flight -> GetGimbalStatus() == PAYLOAD_STATUS::OPERATIONAL || flight -> GetGimbalStatus() == PAYLOAD_STATUS::DEFAULT) {return true;}
    else { return false;}
}


bool CameraStatsusTest(Flights *flight)
{   
    if (flight -> GetCameraStatus() == PAYLOAD_STATUS::OPERATIONAL || flight -> GetGimbalStatus() == PAYLOAD_STATUS::DEFAULT) {return true;}
    else { return false;}
}

bool DistanceStatusTest(Flights *flight)
{   
    if (flight -> GetDistanceStatus() == PAYLOAD_STATUS::OPERATIONAL || flight -> GetGimbalStatus() == PAYLOAD_STATUS::DEFAULT) {return true;}
    else { return false;}
}


bool PositionTest(Flights *flight)
{
    nlab::lib::Vector3f positionNed = flight -> GetPositionNED();
    
    if (((positionNed(0) >= -50) && (positionNed(0) <50)) &&
    ((positionNed(1) >= -50) && (positionNed(1) <50)) &&
    ((positionNed(2) >= 1) && (positionNed(2) <101))) {return true;}
    else {return false;}
}

bool VelocityTest(Flights *flight)
{
    nlab::lib::Vector3f velocity = flight -> GetVelocity();
    
    if (((velocity(0) >= -3) && (velocity(0) < 3)) &&
    ((velocity(1) >= -3) && (velocity(1) < 3)) &&
    ((velocity(2) >= -3) && (velocity(2) < 3))) {return true;}
    else {return false;}
}

bool AttitudeTest(Flights *flight)
{
    nlab::lib::Vector3f attitude = flight -> GetAttitude();
    
    if (((attitude(0) >= -30) && (attitude(0) < 30)) &&
    ((attitude(1) >= -30) && (attitude(1) < 30)) &&
    ((attitude(2) >= -180) && (attitude(2) < 180))) {return true;}
    else {return false;}
}

bool SkydioPositionTest(Flights *flight)
{
    nlab::lib::Vector3f positionNed = flight -> GetPositionNED();
    
    if (((positionNed(0) >= -50*0.9144f) && (positionNed(0) <50*0.9144f)) &&
    ((positionNed(1) >= -50*0.9144f) && (positionNed(1) <50*0.9144f)) &&
    ((positionNed(2) >= 1*0.9144f) && (positionNed(2) <101*0.9144f))) {return true;}
    else {return false;}
}

bool SkydioVelocityTest(Flights *flight)
{
    nlab::lib::Vector3f velocity = flight -> GetVelocity();
    
    if (((velocity(0) >= -3*0.9144f) && (velocity(0) < 3*0.9144f)) &&
    ((velocity(1) >= -3*0.9144f) && (velocity(1) < 3*0.9144f)) &&
    ((velocity(2) >= -3*0.9144f) && (velocity(2) < 3*0.9144f))) {return true;}
    else {return false;}
}

    FCInputImpl* fcinputm300 = new FcInputM300();
    Flights* m300 = fcinputm300 -> DataExtractApiToMC();

    FCInputImpl* fcinputm600 = new FcInputM600();
    Flights* m600 = fcinputm600 -> DataExtractApiToMC();

    FCInputImpl* fcinputmavic = new FcInputMavic();
    Flights* mavic = fcinputmavic -> DataExtractApiToMC();

    FCInputImpl* fcinputskydio = new FcInputSkydio();
    Flights* skydio = fcinputskydio -> DataExtractApiToMC();

TEST(StatusTest,statustest)
{
    assert(GPSHealthTest(m300));
    assert(GPSHealthTest(m600));
    assert(GPSHealthTest(mavic));

    assert(FlightStatusTest(m300));
    assert(FlightStatusTest(m600));
    assert(FlightStatusTest(mavic));

    assert(GimbalStatusTest(m300));
    assert(GimbalStatusTest(m600));
    assert(GimbalStatusTest(mavic));

    assert(CameraStatsusTest(m300));
    assert(CameraStatsusTest(m600));
    assert(CameraStatsusTest(mavic));

    assert(DistanceStatusTest(m300));
    assert(DistanceStatusTest(m600));
    assert(DistanceStatusTest(mavic));
}

TEST(NavigationTest,navigationtest)
{
    assert(PositionTest(m300));
    assert(VelocityTest(m300));
    assert(AttitudeTest(m300));

    assert(PositionTest(m600));
    assert(AttitudeTest(m600));

    assert(PositionTest(mavic));
    assert(VelocityTest(mavic));
    assert(AttitudeTest(mavic));
}

TEST(SkydioTest,skydiotest)
{
    assert(PositionTest(skydio));
    assert(VelocityTest(skydio));
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}