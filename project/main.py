from time import sleep
from machine import Pin

led = Pin(0, mode= Pin.OUT)
bt = Pin(1, mode= Pin.IN)

while (1):
  if not(bt.value()):
    led.value(not led.value())
    sleep(.2)