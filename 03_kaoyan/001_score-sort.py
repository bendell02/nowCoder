class Student:
    def __init__(self, ID, name, grade):
        self.ID = ID
        self.name = name
        self.grade = grade
    def __cmp__(self, other):
        if self.grade != other.grade:
            return cmp(self.grade, other.grade)
        else:
            return cmp(self.ID, other.ID)

def myCmp(one, other):
    if one.grade != other.grade:
        return -cmp(one.grade, other.grade)
    else:
        return cmp(one.ID, other.ID)
while True:
    try:
        N = input()
        m = input()
        students = [0]*N
        for i in range(N):
            name, grade = raw_input().split()
            students[i] = Student(i, name, int(grade))
        if m == 0:
            students.sort(myCmp)
        else:
            students.sort()

        for item in students:
            print item.name, item.grade
    except:
        break

