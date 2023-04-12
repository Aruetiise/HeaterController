import time
import sys
from luma.core.interface.serial import spi
from luma.lcd.device import st7735
from luma.core.render import canvas

class ScreenController:
    def __init__(self):
        self.screen = None
        self.s = spi(port=0, device=0, cs_high=True, gpio_DC=23, gpio_RST=24)
        self.device=st7735(self.s,rotate=0,width=160,height=128,h_offset=0,v_offset=0,bgr=False)
        with canvas(self.device) as draw:
            self.draw = draw
    
    def showBaseStats(self):
        self.draw.text((10, 60), 'AZ-Delivery', fill='red')
        self.draw.line((130, 124, 155, 4), fill='yellow')
    
    def showMenu(self):
        pass
    
    def showAddSlot(self):
        pass
    
    def showAddStart(self):
        pass
    
    def showAddEnd(self):
        pass
    
    def showAddPause(self):
        pass
    
    def showSettings(self):
        pass
    
    def disableScreen(self):
        self.device.hide()
    
    def enableScreen(self):
        self.device.show()
