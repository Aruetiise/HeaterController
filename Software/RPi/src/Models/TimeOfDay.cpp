//
// Created by Julius on 18.03.2023.
//
#include "TimeOfDay.h"
#include <stdexcept>
#include <iostream>

TimeOfDay::TimeOfDay() {
    setHour(0);
    setMinute(0);
}

TimeOfDay::TimeOfDay(int hour, int minute) {
    std::cout << "hour: " << hour << " minute: " << minute << std::endl;
    setHour(hour);
    setMinute(minute);
}

void TimeOfDay::setHour(int hour) {
    if(hour <24 && hour >= 0)
        this->hour = hour;
    else
        throw std::invalid_argument("Hour value has to be between 0 and 23");
}

void TimeOfDay::setMinute(int minute) {
    if(minute <60 && minute >= 0)
        this->min = minute;
    else
        throw std::invalid_argument("Minute value has to be between 0 and 59");
}

int TimeOfDay::getHour() const{
    return hour;
}

int TimeOfDay::getMinute() const{
    return min;
}

bool TimeOfDay::operator<(const TimeOfDay &other) const{
    if(this->hour!=other.hour){
        return this->hour < other.hour;
    }else{
        return this->min < other.min;
    }
}

bool TimeOfDay::operator<=(const TimeOfDay &other) const{
    if(this->hour!=other.hour){
        return this->hour < other.hour;
    }else{
        return this->min <= other.min;
    }
}

bool TimeOfDay::operator>(const TimeOfDay &other) const{
    if(this->hour!=other.hour){
        return this->hour > other.hour;
    }else{
        return this->min > other.min;
    }
}

bool TimeOfDay::operator>=(const TimeOfDay &other) const{
    if(this->hour!=other.hour){
        return this->hour > other.hour;
    }else{
        return this->min >= other.min;
    }
}

bool TimeOfDay::operator==(const TimeOfDay &other) const{
    return this->hour == other.hour && this->min == other.min;
}

bool TimeOfDay::operator!=(const TimeOfDay &other) const{
    return this->hour != other.hour || this->min != other.min;
}

TimeOfDay TimeOfDay::operator+(const TimeOfDay &other) const{
    int hour = this->hour;
    int min = this->min;

    min += other.min;
    if(min >= 60) hour++;
    min %= 60;

    hour += other.hour;
    hour %=24;

    return TimeOfDay(hour,min);
}

TimeOfDay TimeOfDay::operator-(const TimeOfDay &other) const{
    int hour = this->hour;
    int min = this->min;

    min -= other.min;
    if(min <0) hour--;
    min += 60;

    hour -= other.hour;
    if(hour <0)
        hour +=24;

    return TimeOfDay(hour,min);
}