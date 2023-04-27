from ScreenController import ScreenController
import time

screenController = ScreenController()
screenController.showBaseStats()

while(True):
    screenController.showBaseStats()
    print("wainting")
    time.sleep(5)