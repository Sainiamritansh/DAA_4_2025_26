#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int k = 3;
    vector<int> scores = {10, 20, 5, 15, 25, 8};

    priority_queue<int, vector<int>, greater<int>> topKScores;

    for (int currentScore : scores) {
        topKScores.push(currentScore);

        if (topKScores.size() > k) {
            topKScores.pop();
        }

        if (topKScores.size() < k) {
            cout << -1 << endl;
        } else {
            cout << topKScores.top() << endl;
        }
    }

    return 0;
}