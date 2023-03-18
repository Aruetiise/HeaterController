//
// Created by Julius on 18.03.2023.
//
#include "HeatingTimeslot.h"
#include "TimeOfDay.h"
#include <stdexcept>

HeatingTimeslot::HeatingTimeslot(){
    this->startTime = TimeOfDay(0,0);
    this->endTime = TimeOfDay(23,59);
}

void HeatingTimeslot::setStartTime(TimeOfDay time) {
    if(time < endTime)
        this->startTime = time;
    else
        throw std::invalid_argument("The start time has to be before the end time");
}

void HeatingTimeslot::setEndTime(TimeOfDay time) {
    if(time > startTime)
        this->endTime = time;
    else
        throw std::invalid_argument("The end time has to be after the start time");
}

TimeOfDay HeatingTimeslot::getStartTime() {
    return this->startTime;
}

TimeOfDay HeatingTimeslot::getEndTime() {
    return this->endTime;
}

bool HeatingTimeslot::isInTimeslot(TimeOfDay currentTime) const {
    return currentTime >= startTime && currentTime <= endTime;
}

TimeOfDay HeatingTimeslot::getDuration() const {
    return endTime-startTime;
}

TimeOfDay HeatingTimeslot::getRemainingTime(TimeOfDay currentTime) const {
    return endTime-currentTime;
}

void HeatingTimeslot::setTargetTemperature(float temp) {
    this->targetTemperature = temp;
}

float HeatingTimeslot::getTargetTemperature() const {
    return this->targetTemperature;
}

int shiftWeekStartFromSundayToMonday(int day) {
    return (day + 6) % 7;
}