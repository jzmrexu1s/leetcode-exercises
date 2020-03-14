//
// Created by Chengwei Zhang on 3/15/20.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        long end = dividend;
        long sor = divisor;
        bool isPos = ((end > 0 && sor > 0) || (end < 0 && sor < 0)) ? true: false;
        end = abs(end);
        sor = abs(sor);
        if (isPos) return divStep(end, sor);
        return -divStep(end, sor);
    }
    long divStep(long dividend, long divisor) {
        if (dividend < divisor) return 0;
        long extended = divisor;
        long count = 1;
        while (extended + extended <= dividend) {
            extended += extended;
            count += count;
        }
        return divStep(dividend - extended, divisor) + count;
    }
};

int main() {
    Solution solution;
    int res = solution.divide(INT_MAX, 2);
    cout << res;
}