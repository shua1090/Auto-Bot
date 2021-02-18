from ctypes import cdll
import os

path = os.getcwd() + "/libfoo.so"
lib = cdll.LoadLibrary(path)
func = lib.testFunc()
print(type(func))
print(func)

