//
// Created by Julius on 18.03.2023.
//

#ifndef RPI_HEATINGTIMESLOT_H
#define RPI_HEATINGTIMESLOT_H
#include "TimeOfDay.h"
class HeatingTimeslot{
public:
    HeatingTimeslot();
    void setStartTime(TimeOfDay time);
    void setEndTime(TimeOfDay time);
    void getStartTime();
    void getEndTime(TimeOfDay time);
    bool isInTimeslot(TimeOfDay currentTime) const;

    TimeOfDay getDuration() const;
    TimeOfDay getRemainingTime(TimeOfDay currentTime) const;

    void setTargetTemperature(float temp);
    float getTargetTemperature() const;

    static int shiftWeekStartFromSundayToMonday(int day);
private:
    TimeOfDay startTime;
    TimeOfDay endTime;
    float targetTemperature;
};
#endif //RPI_HEATINGTIMESLOT_H
