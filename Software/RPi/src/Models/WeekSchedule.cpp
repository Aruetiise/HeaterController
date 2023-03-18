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
#include "date/tz.h"

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

bool WeekSchedule::isCurrentlyInHeatingTimeslot() const {
    // Get the current time in the Berlin timezone
    auto berlin = date::locate_zone("Europe/Berlin");
    auto now = std::chrono::system_clock::now();
    auto current_time = date::make_zoned(berlin, now).get_local_time();

    // Get the current day of the week
    time_t t = std::chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&t);
    int currentDay = HeatingTimeslot::shiftWeekStartFromSundayToMonday(localTime->tm_wday);

    // Check if the current time falls within any heating timeslot for the current day
    const std::vector<HeatingTimeslot>& slotsForCurrentDay = getSlotsForDay(currentDay);
    for (const HeatingTimeslot& slot : slotsForCurrentDay) {
        if (slot.isInTimeslot(current_time)) {
            return true;
        }
    }

    // If we get here, the current time does not fall within any heating timeslot
    return false;
}
