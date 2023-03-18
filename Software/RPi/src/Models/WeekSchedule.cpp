//
// Created by Julius on 18.03.2023.
//

#include "WeekSchedule.h"
WeekSchedule::WeekSchedule() {}

void WeekSchedule::addTimeslot(int day, HeatingTimeslot slot) {
    schedule[day].push_back(slot);
}

void WeekSchedule::removeTimeslot(int day, HeatingTimeslot slot) {
    schedule[day].remove(slot);
}

void WeekSchedule::listTimeslots() {
    for (int day = 0; day < 7; day++) {
        std::cout << "Day " << day << ":\n";
        for (HeatingTimeslot& slot : schedule[day]) {
            std::cout << "Start time: " << slot.getStartTime() << ", End time: " << slot.getEndTime() << ", Target temperature: " << slot.getTargetTemperature() << std::endl;
        }
    }
}

void WeekSchedule::sortTimeslots() {
    for (int day = 0; day < 7; day++) {
        schedule[day].sort([](const HeatingTimeslot& a, const HeatingTimeslot& b) {
            return a.getStartTime() < b.getStartTime();
        });
    }
}