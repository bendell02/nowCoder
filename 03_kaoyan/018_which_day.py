commonYear = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
leapYear = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]

def whichDay(year, month, day):
    rlt = 0
    if (year%4==0 and year%100) or (year%400==0):
        rlt = leapYear[month-1]
    else:
        rlt = commonYear[month-1]
    rlt += day
    return rlt

while True:
    try:
        year, month, day = map(int, raw_input().strip().split())
        print whichDay(year, month, day)
    except:
        break
