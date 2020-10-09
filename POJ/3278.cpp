
#include <iostream>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

struct State {
    int place;
    int time;
};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    bool visited[100001];
    memset(visited, false, sizeof(visited));
    queue<State> q;
    State initState = {n, 0};
    q.push(initState);
    int res = 0;
    while (!q.empty()) {
        State curState = q.front();
        if (curState.place == k) {
//            cout << res << endl;
            res = curState.time;
            break;
        }
        q.pop();
        for (int i = 0; i < 3; i ++) {
            State newState = {0, curState.time + 1};
            if (i == 0) {newState.place = curState.place - 1;}
            else if (i == 1) {newState.place = curState.place + 1;}
            else {newState.place = curState.place * 2;}
            if (newState.place >= 0 && newState.place <= 100000 && !visited[newState.place]) {
                visited[newState.place] = true;
                q.push(newState);
            }
        }
    }
    cout << res << endl;
    return 0;
}