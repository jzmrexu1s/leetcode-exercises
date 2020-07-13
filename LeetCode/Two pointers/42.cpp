//
// Created by Chengwei Zhang on 5/7/20.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size == 0 || size == 1 || size == 2) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        while (height[l] == 0) {
            l ++;
            r ++;
        }
        while (l < size) {
            r = l + 1;
            if (r == size) break;
            int highest = l;
            int shorter = r;
            while (r < size && height[r] < height[l]) {
                if (height[r] >= height[shorter]) {
                    shorter = r;
                }
                r ++;
            }
            if (r == size) {
                while (l < shorter) {
                    if (height[shorter] - height[l] > 0) sum += height[shorter] - height[l];
                    l ++;
                }

            } else {
                while (l < r) {
                    sum += height[highest] - height[l];
                    l ++;
                }
            }
        }
        return sum;

    }
};

int main() {
    Solution solution;
    vector<int> heights {0,1,0,2,1,0,1,3,2,1,2,1};
    int r = solution.trap(heights);
    cout << "Result: " << r << endl;
}