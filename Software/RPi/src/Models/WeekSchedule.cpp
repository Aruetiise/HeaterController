//
// Created by Julius on 18.03.2023.
//

#include "WeekSchedule.h"
#include "HeatingTimeslot.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <algorithm>

WeekSchedule::WeekSchedule() {}

void WeekSchedule::addTimeslot(int day, HeatingTimeslot slot) {
    if(day <7 && day >= 0 )
        schedule[day].push_back(slot);
    else
        throw std::invalid_argument("Day has to be between 0(Monday) and 6(Sunday). Given" + std::to_string(day));

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

const std::list<HeatingTimeslot>& WeekSchedule::getSlotsForDay(int day) const{
    if(day <7 && day >= 0 )
        return schedule[day];
    else
        throw std::invalid_argument("Day has to be between 0(Monday) and 6(Sunday). Given" + std::to_string(day));
}

bool WeekSchedule::isCurrentlyInHeatingTimeslot() const {
    // Get the current time
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&t);

    // Get the current day of the week
    int currentDay = localTime.tm_wday == 0 ? 6 : localTime.tm_wday - 1;

    // Check if the current time falls within any heating timeslot for the current day
    const std::vector<HeatingTimeslot>& slotsForCurrentDay = getSlotsForDay(currentDay);
    auto current_time = std::chrono::system_clock::from_time_t(std::mktime(&localTime));
    for (const HeatingTimeslot& slot : slotsForCurrentDay) {
        if (slot.isInTimeslot(TimeOfDay(current_time))) {
            return true;
        }
    }

    // If we get here, the current time does not fall within any heating timeslot
    return false;
}
