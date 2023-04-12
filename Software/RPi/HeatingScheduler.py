from datetime import datetime, time
from HeatingPeriode import HeatingPeriode

class Scheduler:
    def __init__(self):
        self._heating_periods = {
            "Monday": [],
            "Tuesday": [],
            "Wednesday": [],
            "Thursday": [],
            "Friday": [],
            "Saturday": [],
            "Sunday": []
        }
        
    def add_heating_period(self, heating_period: HeatingPeriode):
        self._heating_periods[heating_period._day].append(heating_period)
        
    def remove_heating_period(self, heating_period: HeatingPeriode):
        day_heating_periods = self._heating_periods[heating_period._day]
        if heating_period not in day_heating_periods:
            raise ValueError("Heating period not found")
        day_heating_periods.remove(heating_period)
        
    def current_Heat(self):
        now = datetime.now()
        day = now.strftime("%A").lower()
        if day in self._heating_periods:
            for heating_period in self._heating_periods[day]:
                start_time = datetime.strptime(heating_period._start_time, "%H:%M").time()
                end_time = datetime.strptime(heating_period._end_time, "%H:%M").time()
                if start_time <= now.time() <= end_time:
                    return heating_period._temperature
        return -1