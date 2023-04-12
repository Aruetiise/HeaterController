from ScreenController import ScreenController
import time

screenController = ScreenController()
screenController.showBaseStats()

while(True):
    print("wainting")
    time.sleep(5)