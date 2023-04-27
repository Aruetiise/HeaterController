from luma.core.interface.serial import spi
from luma.lcd.device import st7735
from luma.core.render import canvas
from PIL import ImageFont

class ScreenController:
    def __init__(self):
        self.width = 160
        self.height=128

        self.font_type = ImageFont.truetype('Helvetica.ttf', 22)
        s = spi(port=0, device=0, cs_high=True, gpio_DC=23, gpio_RST=24)
        self.device=st7735(s,rotate=0,width=160,height=128,h_offset=0,v_offset=0,bgr=False)
    
    def showBaseStats(self):
            with canvas(self.device) as draw:
            #Grid
                draw.line((0,32,self.width,32), fill='white')
                draw.line((0,64,self.width,64), fill='white')
                draw.line((0,96,self.width,96), fill='white')

            #ROW 0
                #Current stats
                draw.text((3,3),'20°C', font=self.font_type, fill='white')
                draw.text((57,3),'53%', font=self.font_type, fill='white')
                draw.text((105,3),'16:33', font=self.font_type, fill='white')

            #ROW 1
                draw.text((3,35),'Ziel:', font=self.font_type, fill='white')
                draw.text((50,35),'19°C', font=self.font_type, fill='white')
                #is currently heating
                draw.ellipse((120, 35, 143, 58), outline=(0, 255, 0), fill='green')
                
            #ROW 2
                #Heating timer
                #Is heating time
                draw.ellipse((5, 67, 28, 92), outline=(0, 255, 0), fill='green')

                #start time
                draw.text((32,67),'14:30', font=self.font_type, fill='white')

                #arrow
                draw.line((86,80,100,80), fill='white')
                draw.line((95,77,100,80), fill='white')
                draw.line((95,83,100,80), fill='white')

                #end time
                draw.text((105,67),'22:30', font=self.font_type, fill='white')

            #ROW 3
                #is heating time
                draw.ellipse((5, 99, 28, 122), outline=(255, 0, 0), fill='red')
                #start time
                draw.text((32,99),'14:30', font=self.font_type, fill='white')

                #arrow
                draw.line((86,112,100,112), fill='white')
                draw.line((95,109,100,112), fill='white')
                draw.line((95,115,100,112), fill='white')

                #end time
                draw.text((105,99),'22:30', font=self.font_type, fill='white')

    
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
