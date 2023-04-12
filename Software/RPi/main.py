import time
import sys
from luma.core.interface.serial import spi
from luma.lcd.device import st7735
from luma.core.render import canvas

s = spi(port=0, device=0, cs_high=True, gpio_DC=23, gpio_RST=24)
device=st7735(s,rotate=0,width=160,height=128,h_offset=0,v_offset=0,bgr=False)

def primitives(device, draw):
        # Draw a rectangle of the same size of screen
        draw.rectangle(device.bounding_box, outline='white')
        # Draw a rectangle
        draw.rectangle((4, 4, 80, 124), outline='blue', fill=(22, 55, 55))
        # Draw an ellipse
        draw.ellipse((6, 6, 78, 122), outline=(254, 155, 0), fill='green')
        # Draw a triangle
        draw.polygon([(90,124), (100,4), (120,124)], outline='blue', fill='red')
        # Draw an X
        draw.line((130, 4, 155, 124), fill='yellow')
        draw.line((130, 124, 155, 4), fill='yellow')
        # Print 'AZ-Delivery'
        draw.text((10, 60), 'AZ-Delivery', fill='red')

print('[Press CTRL + C to end the script!]')
try:
        
        print('Testing basic graphics.')
        with canvas(device) as draw:
                primitives(device, draw)
        time.sleep(3)
        print('Testing display ON/OFF.')
        for _ in range(5):
                time.sleep(0.5)
                device.hide()
                time.sleep(0.5)
                device.show()
        print('Testing clear display.')
        time.sleep(2)
        device.clear()
        print()
        time.sleep(2)
except KeyboardInterrupt:
        device.backlight(True) # if backlight connected to GPIO18
        device.cleanup()
        print('Script end!')
