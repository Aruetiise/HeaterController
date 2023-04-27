from ScreenController import ScreenController
import time

screenController = ScreenController()
print('[Press CTRL + C to end the script!]')
try:
        screenController.showBaseStats()
        screenController.enableScreen()
        time.sleep(3)
except KeyboardInterrupt:
        screenController.cleanup()
        print('Script end!')
