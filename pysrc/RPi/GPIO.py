from random import randint

# class PWM():
    #     def start(dc): pass
    #     def stop(self): pass
    #     def ChangeDutyCycle(dc): pass
    #     def ChangeFrequency(frequency): pass    # Values

LOW = 0
HIGH = 1    # Modes
BCM = 11
BOARD = 10    # Pull
PUD_OFF = 20
PUD_DOWN = 21
PUD_UP = 22    # Edges
RISING = 31
FALLING = 32
BOTH = 33    # Functions
OUT = 0
IN = 1
SERIAL = 40
SPI = 41
I2C = 42
HARD_PWM = 43
UNKNOWN = -1    # Versioning
RPI_REVISION = 2
VERSION = '0.5.6'
INPUTS = [None] * 26

def setwarnings(a): pass    
def setmode(a): pass    
# def getmode(): return BCM    
def setup(channel, state, initial=0, pull_up_down=None): pass    
def input(channel):
    if INPUTS[channel] is not None:
        return INPUTS[channel]
    return randint(0, 1)    
def set_input(channel, value):
    INPUTS[channel] = value    
def cleanup(a=None): pass    
def output(channel, state): pass    
def wait_for_edge(channel, edge): pass    
def add_event_detect(channel, edge, callback=None, bouncetime=None): pass    
def add_event_callback(channel, callback=None): pass    
def remove_event_detect(channel): pass    
def event_detected(channel): return False    
def gpio_function(channel): return OUT
