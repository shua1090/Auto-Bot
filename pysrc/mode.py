pins = """
     1 || 2      
  8  3 || 4      
  9  5 || 6      
  7  7 || 8   15 
     9 || 10  16 
  0 11 || 12  1  
  2 13 || 14     
  3 15 || 16  4  
    17 || 18  5  
 12 19 || 20     
 13 21 || 22  6  
 14 23 || 24  10 
    25 || 26  11
"""

import re

pinList = []

for line in pins.splitlines():
   left = re.search(r"\|\s+(\d+)\s+(\d+)", line)
   right = re.search(r"^\s+(\d+)\s+(\d+)", line)
   if left:
      pinList.append( (int(left.groups()[0]),  int(left.groups()[1])) )
   if right:
      pinList.append( (int(right.groups()[1]), int(right.groups()[0])) )

pinList.sort(key=lambda x: x[1])
# print(*pinList, sep="\n")

for item in pinList:
   print(f"P{item[0]}", end=", ")