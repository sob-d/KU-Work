#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Number {
    int value;
    int freq;
};

bool compareNumbers(const Number& a, const Number& b) {
    if (a.freq != b.freq) {
        return a.freq > b.freq;
    }
    return a.value < b.value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    map<int, int> counts;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        counts[val]++;
    }

    vector<Number> result;
    for (auto const& [val, freq] : counts) {
        result.push_back({val, freq});
    }

    sort(result.begin(), result.end(), compareNumbers);

    for (const auto& num : result) {
        cout << num.value << "\n";
    }

    return 0;
}