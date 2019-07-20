import math
while True:
    try:
        x0,y0,z0,x1,y1,z1 = map(float, raw_input().strip().split())
        r = math.sqrt((x1-x0)**2+(y1-y0)**2+(z1-z0)**2)
        v = 4*math.pi*(r**3)/3
        print '%.3f %.3f' % (r,v)
    except:
        break
