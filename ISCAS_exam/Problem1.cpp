//
// Created by Chengwei Zhang on 7/31/20.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Group{
    string word;
    int weight;
};

bool comp(const Group& g1, const Group& g2) {
    return g1.weight > g2.weight;
}

int main() {
    int dic[26] = {4, 2, 5, 6, 1, 4, 5, 6, 7, 2, 3, 4, 8, 9, 3, 1, 2, 6, 8, 9, 2, 6, 3, 2, 5, 7};
    int n, m;
    scanf("%d%d", &n, &m);
    Group* words = new Group[n];
    for (int i = 0; i < n; i ++) {
        string word;
        cin >> word;
        Group g = {word, 0};

        for (int j = 0; j < word.size(); j ++) {
            g.weight += dic[word[j] - 'a'];
        }
        words[i] = g;
    }
    sort(words, words + n, comp);
    for (int i = 0; i < m - 1; i ++) {
        cout << words[i].word << " " << words[i].weight << endl;
    }
    cout << words[m - 1].word << " " << words[m - 1].weight;
    return 0;
}