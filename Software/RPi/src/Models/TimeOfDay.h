//
// Created by Julius on 18.03.2023.
//

#ifndef RPI_TIMEOFDAY_H
#define RPI_TIMEOFDAY_H

#include <ostream>

class TimeOfDay{
public:
    TimeOfDay();
    TimeOfDay(int hour, int minute);
    TimeOfDay(const std::chrono::system_clock::time_point& systemTime);
    void setHour(int hour);
    void setMinute(int minute);
    int getHour() const;
    int getMinute() const;
    bool operator<(const TimeOfDay& other) const;
    bool operator<=(const TimeOfDay& other) const;
    bool operator>(const TimeOfDay& other) const;
    bool operator>=(const TimeOfDay& other) const;
    bool operator==(const TimeOfDay& other) const;
    bool operator!=(const TimeOfDay& other) const;
    TimeOfDay operator+(const TimeOfDay& other) const;
    TimeOfDay operator-(const TimeOfDay& other) const;
    friend std::ostream& operator<<(std::ostream& os, const TimeOfDay& time);
private:
    int hour;
    int min;
};
#endif //RPI_TIMEOFDAY_H
