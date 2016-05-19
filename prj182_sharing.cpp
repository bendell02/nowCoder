#include <iostream>
#include <map>
#include <string>

using namespace std;

int getLength(string head, map<string, string> &nodes)
{
    int length = 0;
    while(head != "-1") {
        length++;
        head = nodes[head];
    }
    return length;
}

string getFirstCommonNode(string &head1, string &head2, map<string, string> &nodes)
{
    int l1 = getLength(head1, nodes), l2 = getLength(head2, nodes);
    if(l1 < l2) {
        swap(l1, l2); swap(head1, head2);
    }
    for(int i=0; i<(l1-l2); i++) {
        head1 = nodes[head1];
    }
    string rlt = "-1";
    for(int i=0; i<l2; i++) {
        if(head1 == head2) {
            rlt = head1; break;
        }
        head1 = nodes[head1];
        head2 = nodes[head2];
    }
    return rlt;
}

int main()
{
    ios::sync_with_stdio(false);
    string head1, head2; int N;
    while(cin >> head1 >> head2 >> N) {
        map<string, string> nodes;
        string first, second, ch;
        for(int i=0; i<N; i++) {
            cin >> first >> ch >> second;
            nodes[first] = second;
        }
        cout << getFirstCommonNode(head1, head2, nodes) << endl;
    }
    return 0;
}
