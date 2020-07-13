//
// Created by Chengwei Zhang on 7/14/20.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> nums;
        while (n > 0) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
            n --;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
}