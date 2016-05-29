#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

class Student
{
public:
    int ID, grade; char name[9];
    Student() {}
}students[100001];

bool myCmp1(const Student &a, const Student &b)
{
    return a.ID<b.ID;
}

bool myCmp2(const Student &a, const Student &b) {
    int tmp = strcmp(a.name, b.name);
    if(tmp) {
        return tmp<0;
    } else {
        return a.ID<b.ID;
    }
}

bool myCmp3(const Student &a, const Student &b) {
    if(a.grade != b.grade) {
        return a.grade<b.grade;
    } else {
        return a.ID<b.ID;
    }
}

int main()
{
    int N, C, idx=0;
    while(scanf("%d %d", &N, &C) && N!=0) {
        idx++;
        for(int i=0; i<N; i++) {
            scanf("%d %s %d", &students[i].ID, students[i].name, &students[i].grade);
        }
        if(C==1) {
            sort(students, students+N, myCmp1);
        } else if(C==2) {
            sort(students, students+N, myCmp2);
        } else {
            sort(students, students+N, myCmp3);
        }
        printf("Case %d:\n", idx);
        for(int i=0; i<N; i++) {
            printf("%06d %s %d\n", students[i].ID, students[i].name, students[i].grade);
        }
    }
    return 0;
}
