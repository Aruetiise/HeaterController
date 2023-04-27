from luma.core.interface.serial import spi
from luma.lcd.device import st7735
from luma.core.render import canvas
from PIL import ImageFont

class ScreenController:
    def __init__(self):
        self.width = 160
        self.height=128
        
        self.font_type = ImageFont.truetype('times_new_roman_bold.ttf', 22)

        s = spi(port=0, device=0, cs_high=True, gpio_DC=23, gpio_RST=24)
        self.device=st7735(s,rotate=0,width=160,height=128,h_offset=0,v_offset=0,bgr=False)
        self.device.backlight(False)
    
    def showBaseStats(self):
            with canvas(self.device) as draw:
                draw.line((0,32,self.width,32), fill='white')
                draw.line((0,64,self.width,64), fill='white')
                draw.line((0,96,self.width,96), fill='white')

                draw.text((3,3),'20°C', font=self.font_type, fill='white')
                draw.text((65,3),'53%', font=self.font_type, fill='white')
                draw.text((105,3),'16:33', font=self.font_type, fill='white')

                draw.ellipse((5, 67, 28, 92), outline=(0, 255, 0), fill='green')

                draw.text((32,67),'14:30', font=self.font_type, fill='white')

                draw.line((85,80,100,80), fill='white')
                draw.line((90,75,100,80), fill='white')
                draw.line((90,85,100,80), fill='white')

                draw.text((105,67),'22:30', font=self.font_type, fill='white')

    
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

    def cleanup(self):
        self.device.cleanup()
