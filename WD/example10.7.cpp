//
// Created by Chengwei Zhang on 10/6/20.
//

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n, m;
    unordered_map<string, string> dic;
    scanf("%d", &n);
    cin.ignore();
    for (int i = 0; i < n; i ++) {
        string tmp;
        getline(cin, tmp);
        int sep = tmp.find(" ");
        dic[tmp.substr(0, sep)] = tmp;
    }
    scanf("%d", &m);
    cin.ignore();
    for (int i = 0; i < m; i ++) {
        string query;
        getline(cin, query);
        string r = dic[query];
        if (r == "") cout << "No Answer!" << endl;
        else cout << r << endl;
    }
    return 0;
}