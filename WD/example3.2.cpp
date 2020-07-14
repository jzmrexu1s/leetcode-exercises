//
// Created by Chengwei Zhang on 7/14/20.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student{
    int number;
    int score;
};

bool comp(const Student &s1, const Student &s2) {
    return s1.score < s2.score || (s1.score == s2.score && s1.number < s2.number);
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<Student> students;
        while (n > 0) {
            int number, score;
            scanf("%d%d", &number, &score);
            Student student{number, score};
            students.push_back(student);
            n --;
        }
        sort(students.begin(), students.end(), comp);
        for (int i = 0; i < students.size(); i ++) {
            cout << students[i].number << " " << students[i].score << endl;
        }
    }
    return 0;
}