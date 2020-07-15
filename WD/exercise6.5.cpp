//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int num1, int num2) {
    if (num2 == 0) return num1;
    return gcd(num2, num1 % num2);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int* nums = new int[n];
        for (int i = 0; i < n; i ++) {
            int t;
            scanf("%d", &t);
            nums[i] = t;
        }
        int count = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j) {
                    if (nums[i] > nums[j] && gcd(nums[i], nums[j]) == 1) count ++;
                }
            }
        }
        cout << count << endl;
    }
}