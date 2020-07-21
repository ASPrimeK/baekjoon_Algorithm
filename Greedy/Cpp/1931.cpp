// 회의실배정
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class schedule {
   public:
    unsigned int start;
    unsigned int end;
    schedule(unsigned int s, unsigned int e) {
        start = s;
        end = e;
    }
};
bool cmp(schedule aa, schedule bb) {
    if (aa.end < bb.end) {
        return true;
    } else if (aa.end == bb.end) {
        if (aa.start < bb.start)
            return true;
        else
            return false;
    } else {
        return false;
    }
}
int main() {
    int n, s, e, count = 1;
    cin >> n;
    vector<schedule> t;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        t.push_back(schedule(s, e));
    }
    sort(t.begin(), t.end(), cmp);
    e = t[0].end;

    for (int i = 1; i < n; i++) {
        if (e <= t[i].start) {
            e = t[i].end;
            count++;
        }
    }
    cout << count;
}
