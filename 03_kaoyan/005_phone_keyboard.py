clsHit = {'a':(0, 1), 'b':(0, 2), 'c':(0, 3), 'd':(1, 1), 'e':(1, 2), \
          'f':(1, 3), 'g':(3, 1), 'h':(3, 2), 'i':(3, 3), 'j':(4, 1), \
          'k':(4, 2), 'l':(4, 3), 'm':(5, 1), 'n':(5, 2), 'o':(5, 3), \
          'p':(6, 1), 'q':(6, 2), 'r':(6, 3), 's':(6, 4), 't':(7, 1), \
          'u':(7, 2), 'v':(7, 3), 'w':(8, 1), 'x':(8, 2), 'y':(8, 3), \
          'z':(8, 4)}

while True:
    try:
        s = raw_input()
        preCls = -1
        totalHits = 0
        for ch in s:
            cls, hits = clsHit[ch]
            if cls == preCls:
                totalHits += 2
            totalHits += hits
            preCls = cls
        print totalHits
    except:
        break
