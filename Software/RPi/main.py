from ScreenController import ScreenController
import time

screenController = ScreenController()
print('[Press CTRL + C to end the script!]')
try:
        screenController.showBaseStats()
        screenController.enableScreen()
        while(True):
            screenController.enableScreen()
            screenController.disableScreen()
            
except KeyboardInterrupt:
        screenController.cleanup()
        print('Script end!')
