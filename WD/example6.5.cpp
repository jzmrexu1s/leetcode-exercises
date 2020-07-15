//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>

using namespace std;

int rec(int num1, int num2) {
    if (num2 == 0) return num1;
    return rec(num2, num1 % num2);
}

int main() {
    int num1, num2;
    while (scanf("%d%d", &num1, &num2) != EOF) {
        cout << rec(num1, num2) << endl;
    }
}