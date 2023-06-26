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

TEST(StatusTest,statustest)
{
    FCInputImpl* fcinputm300 = new FcInputM300();
    Flights* m300 = fcinputm300 -> DataExtractApiToMC();

    FCInputImpl* fcinputm600 = new FcInputM600();
    Flights* m600 = fcinputm600 -> DataExtractApiToMC();

    FCInputImpl* fcinputmmavic = new FcInputMavic();
    Flights* mavic = fcinputmmavic -> DataExtractApiToMC();


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



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}