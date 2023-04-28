from datetime import datetime, time
import math

class Scheduler:
    def __init__(self, minTemp : float):
        self._heating_periods = [[minTemp] * 24*60]*7
        

    def setTimePeriode(self, day : int, temperature:float, startH : int, endH : int, startM=0 , endM=0):
        for min in range(startH*60+startM, endH+60+endM):
            self._heating_periods[day][min] = temperature
    
    def current_Heat(self):
        day = self.getCurrentDay()
        currentMinute = dt.strftime("%H") * 60 + dt.strftime("%M")
        return self._heating_periods[day][currentMinute]
    
    def getStartTime(self, time : int):
        day = [self.getCurrentDay()]
        timeTemp = day[time]
        start = time

        while(day[start] == timeTemp and start >0):
            start -= start
        return start

    def getStartTime(self, time : int):
        day = [self.getCurrentDay()]
        timeTemp = day[time]
        end = time

        while(day[end] == timeTemp and end < 60*24-1):
            end -= end
        return end
    
    def formatTime(time : int):
        return str(math.floor(time/60)) + ":" + str(time%60)

    def getCurrentDay():
        return datetime.now().weekday()