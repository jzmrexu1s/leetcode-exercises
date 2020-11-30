//
// Created by Chengwei Zhang on 10/25/20.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

struct Day {
    int from;
    int to;
    int people;
};

int main() {
    int N;
    scanf("%d", &N);
    int* hideouts = new int[N];
    int allPeople = 0;
    for (int i = 0; i < N; i ++) {
        scanf("%d", &hideouts[i]);
        allPeople += hideouts[i];
    }
    int D;
    scanf("%d", &D);
    Day* days = new Day[D];
    for (int i = 0; i < D; i ++) {
        int from, to, people;
        scanf("%d %d %d", &from, &to, &people);
        days[i] = Day{from, to, people};
    }

    int allRescued = 0;

    for (int d = 0; d < D; d ++) {
        unordered_map<int, int> mp;
        bool* rescued = new bool[D];
        int toBeRescued = days[d].people;
        for (int i = days[d].from - 1; i <= days[d].to - 1; i ++) mp[i] = -1;
        for (int i = d; i < D; i ++) {
            rescued[i] = false;
            for (int j = days[d].from - 1; j <= days[d].to - 1; j ++) {
                if (i == j) mp[i] = d;
            }
        }
        while (toBeRescued > 0 && allRescued < allPeople) {
            int sm = 0;
            for (int i = days[d].from - 1; i <= days[d].to - 1; i ++) {
                sm += hideouts[i];
            }
            if (sm == 0) break;
            int t = 999999;
            int sel = 0;
            for (int i = days[d].from - 1; i <= days[d].to - 1; i ++) {
                if (!rescued[i]) {
                    break;
                }
            }
            rescued[sel] = true;
//            for (int i = days[d].from - 1; i <= days[d].to - 1; i ++) {
//                if (mp[i] < t && !rescued[i]) {
//                    t = mp[i];
//                    sel = i;
//                }
//            }

            int thisLocPeople = hideouts[sel];
            cout << toBeRescued << " " << sel << " " << thisLocPeople << endl;

            if (toBeRescued <= thisLocPeople) {
                allRescued += toBeRescued;
                toBeRescued = 0;
                hideouts[sel] -= toBeRescued;
            } else {
                toBeRescued -= hideouts[sel];
                allRescued += hideouts[sel];
                hideouts[sel] = 0;
            }
        }
        for (int i = days[d].from - 1; i <= days[d].to - 1; i ++) {
            hideouts[days[d + 1].from - 1] += hideouts[i - 1];
            hideouts[i - 1] = 0;
        }
    }
    cout << allRescued << endl;
    return 0;
}