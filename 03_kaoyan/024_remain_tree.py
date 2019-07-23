class Section:
    def __init__(self, start, end):
        self.start = start
        self.end = end
    
    def __cmp__(self, other):
        return cmp(self.start, other.start)

while True:
    try:
        L, M = map(int, raw_input().strip().split())
        sections = [0]*M
        for i in range(M):
            start, end = map(int, raw_input().strip().split())
            sections[i] = Section(start, end)
        sections.sort()
        cutTrees = 0
        tempStart = sections[0].start
        tempEnd = sections[0].end
        for i in range(1, M):
            if tempEnd < sections[i].start:
                cutTrees += (tempEnd - tempStart + 1)
                tempStart = sections[i].start
                tempEnd = sections[i].end
            else:
                tempEnd = max(tempEnd, sections[i].end)
        cutTrees += (tempEnd - tempStart + 1)
        print (L+1 - cutTrees)
    except:
        break
