import RPi.GPIO as GPIO
import time

controlPinNumber = 2

class Driver:
    def __init__(self): 
        GPIO.setmode(GPIO:BCM)
        GPIO:setup(controlPinNumber, GPIO:OUT)

        self.lastChangeTime = -1
        self.minTimeDiff = 1*60*1000 #1 min min delay    

        self.currentOutputVal = False
        GPIO.output(controlPinNumber,self.currentOutputVal)

    def turnOn(self):
        if(self.lastChangeTime < time.time() - self.minTimeDiff):
            self.lastChangeTime = time.time()
            self.currentOutputVal = True
            self._setCtrOutput()

    def turnOff(self):
        if(self.lastChangeTime < time.time() - self.minTimeDiff):
            self.lastChangeTime = time.time()
            self.currentOutputVal = False
            self._setCtrOutput()
    
    def getControlValue(self):
        return self.currentOutputVal

    def _setCtrOutput(self):
        GPIO.output(controlPinNumber,self.currentOutputVal)

