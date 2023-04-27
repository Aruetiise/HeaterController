from ScreenController import ScreenController
import time

screenController = ScreenController()
print('[Press CTRL + C to end the script!]')
try:
        screenController.showBaseStats()
        while(True):
            pass
            
except KeyboardInterrupt:
        screenController.cleanup()
        print('Script end!')
