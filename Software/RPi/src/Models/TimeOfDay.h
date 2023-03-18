//
// Created by Julius on 18.03.2023.
//

#ifndef RPI_TIMEOFDAY_H
#define RPI_TIMEOFDAY_H
class TimeOfDay{
public:
    TimeOfDay(int hour, int minute);
    void setHour(int hour);
    void setMinute(int minute);
    void getHour() const;
    void getMinute() const;
    bool operator<(const TimeOfDay& other) const;
    bool operator<=(const TimeOfDay& other) const;
    bool operator>(const TimeOfDay& other) const;
    bool operator>=(const TimeOfDay& other) const;
    bool operator==(const TimeOfDay& other) const;
    bool operator!=(const TimeOfDay& other) const;
    TimeOfDay operator+(const TimeOfDay& other) const;
    TimeOfDay operator-(const TimeOfDay& other) const;
private:
    int hour;
    int min;
};
#endif //RPI_TIMEOFDAY_H
