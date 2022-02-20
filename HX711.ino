
#include "includes.h"
HX711 scale;

boolean getweight()
{
    scale.power_up();
    delay(10);
    scale.begin(cellDoutPin, cellSckPin);
    scale.set_scale(cellDivider);
    scale.set_offset(cellOffset);
    if (scale.is_ready())
    {
        long reading = scale.getunits(5);
        Serial.print("HX711 reading: ");
        Serial.println(reading);
        dtostrf(reading,8,2,weightString)
        scale.power_down();
        return true;
    }
    else //TODO add retry
    {
        Serial.println("HX711 not found.");
        return false
    }
}