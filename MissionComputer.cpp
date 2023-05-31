#include <iostream>
#include "eNumCollections.h"
#include "Flights.h"
#include "FcInputlmpl.h"
#include "FlightM300.h"
#include "FlightM600.h"


int main()
{
    FCInputImpl* fcinputm300 = new FcInputM300();
    Flights* m300 = fcinputm300 -> DataExtractApiToMC();
    m300 -> ShowGPSNum();

    FCInputImpl* fcinputm600 = new FcInputM600();
    Flights* m600 = fcinputm600 -> DataExtractApiToMC();
    m600 -> ShowGPSNum();

    FCInputImpl* fcinputmmavic = new FcInputMavic();
    Flights* mavic = fcinputmmavic -> DataExtractApiToMC();
    mavic -> ShowGPSNum();

  
    return 0;
}

