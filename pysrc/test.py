import RPi.GPIO as io
from time import sleep

io.setmode(io.BOARD)

class Motor:
    def __init__(self, enable: int, pin1: int, pin2: int):
        self.enable = enable
        self.pin1 = pin1
        self.pin2 = pin2

        io.setup(enable, io.OUT)
        io.setup(pin1, io.OUT)
        io.setup(pin2, io.OUT)

    def __del__(self):
        io.cleanup()

    def switch(self):
        self.pin1, self.pin2 = self.pin2, self.pin1

    def drive(self):
        io.output(self.enable, True)
        io.output(self.pin1, True)
        io.output(self.pin2, False)

    def stop(self, full=False):
        io.output(self.enable, False)
        if full:
            io.output(self.pin1, False)
            io.output(self.pin2, False)

left = Motor(11, 13, 15)
dura = float(input("Enter duration (s): "))
left.drive()
sleep(dura)
left.stop(True)
