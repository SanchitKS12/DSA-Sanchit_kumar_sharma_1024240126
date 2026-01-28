#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    vector<Activity> activities;

    for (int i = 0; i < N; i++) {
        activities.push_back({start[i], finish[i]});
    }

    sort(activities.begin(), activities.end(), compare);

    vector<Activity> selected;

    selected.push_back(activities[0]);
    int lastFinish = activities[0].finish;

    for (int i = 1; i < N; i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(activities[i]);
            lastFinish = activities[i].finish;
        }
    }

    cout << "Maximum number of activities = " << selected.size() << endl;
    cout << "Selected activities: ";
    for (auto act : selected) {
        cout << "(" << act.start << ", " << act.finish << ") ";
    }

    return 0;
}
