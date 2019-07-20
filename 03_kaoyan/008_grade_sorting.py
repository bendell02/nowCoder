class Student:
    def __init__(self, ID, grade):
        self.ID = ID
        self.grade = grade
    def __cmp__(self, other):
        if self.grade != other.grade:
            return cmp(self.grade, other.grade)
        else:
            return cmp(self.ID, other.ID)

while True:
    try:
        N = input()
        students = [0]*N
        for i in range(N):
            ID, grade = map(int, raw_input().strip().split())
            students[i] = Student(ID, grade)
        students.sort()
        for item in students:
            print item.ID, item.grade
    except:
        break
