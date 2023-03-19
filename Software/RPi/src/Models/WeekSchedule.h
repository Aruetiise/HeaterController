//
// Created by Julius on 18.03.2023.
//

#ifndef RPI_WEEKSCHEDULE_H
#define RPI_WEEKSCHEDULE_H
#include <iostream>
#include <list>
#include "HeatingTimeslot.h"

const int MONDAY = 0;
const int TUESDAY = 1;
const int WEDNESDAY = 2;
const int THURSDAY = 3;
const int FRIDAY = 4;
const int SATURDAY = 5;
const int SUNDAY = 6;

class WeekSchedule {
public:
    WeekSchedule();
    void addTimeslot(int day, HeatingTimeslot slot);
    void removeTimeslot(int day, HeatingTimeslot slot);
    void listTimeslots();
    const std::list<HeatingTimeslot>& getSlotsForDay(int day) const;
    void sortTimeslots();
    bool isCurrentlyInHeatingTimeslot() const;
private:
    std::list<HeatingTimeslot> schedule[7];
};
#endif //RPI_WEEKSCHEDULE_H
