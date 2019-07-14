#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int N, num;
    while(scanf("%d", &N) != EOF) {
        while(N--) {
            scanf("%d", &num); int rlt;
            if(num>0) {
                rlt = 0; int i=1;
                for(; i*i<num; i++) {
                    if(num%i == 0) rlt += 2;
                }
                if(i*i == num) rlt++;
            } else {
                rlt = 1;
            }
            printf("%d\n", rlt);
        }
    }
    return 0;
}
