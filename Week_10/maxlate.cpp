#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int deadline;
    int duration;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.deadline < b.deadline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Job> jobs(N);
    for (int i = 0; i < N; ++i) {
        cin >> jobs[i].deadline >> jobs[i].duration;
    }

    sort(jobs.begin(), jobs.end(), compareJobs);

    long long current_time = 0;
    long long max_penalty = 0;

    for (int i = 0; i < N; ++i) {
        current_time += jobs[i].duration;

        if (current_time > (long long)jobs[i].deadline + 10) {
            long long penalty = (current_time - jobs[i].deadline - 10) * 1000;
            if (penalty > max_penalty) {
                max_penalty = penalty;
            }
        }
    }

    cout << max_penalty << endl;

    return 0;
}