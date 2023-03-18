//
// Created by Julius on 18.03.2023.
//

#ifndef RPI_TIMEOFDAY_H
#define RPI_TIMEOFDAY_H
class TimeOfDay{
public:
    TimeOfDay();
    TimeOfDay(int hour, int minute);
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
    std::ostream& operator<<(std::ostream& os, const TimeOfDay& time) const;
private:
    int hour;
    int min;
};
#endif //RPI_TIMEOFDAY_H
