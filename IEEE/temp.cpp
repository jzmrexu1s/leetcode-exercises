//
// Created by Chengwei Zhang on 10/24/20.
//

#include <iostream>

using namespace std;

int main() {
    int W, H, A, B, M, C;
    scanf("%d%d%d%d%d%d", &W, &H, &A, &B, &M, &C);

    unsigned long long widthCount = W % A == 0 ? W / A : W / A + 1;
    unsigned long long heightCount = H % B == 0 ? H / B : H / B + 1;

    unsigned long long allCount = widthCount * heightCount;
    unsigned long long pilesMoney = allCount % 10 == 0 ? M * allCount / 10 : M * (allCount / 10 + 1);

    unsigned long long cutMoney = 0;
    if (W % A != 0) cutMoney += C * H;
    if (H % B != 0) cutMoney += C * W;

    cout << cutMoney + pilesMoney << endl;

    return 0;
}