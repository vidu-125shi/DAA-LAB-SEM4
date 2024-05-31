
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
  int start;
  int finish;
};

bool compareActivities(const Activity& a1, const Activity& a2) {
  return a1.finish < a2.finish;
}

int selectMaxActivities(vector<Activity>& activities) {
  int n = activities.size();
  if (n == 0) {
    return 0;
  }
  sort(activities.begin(), activities.end(), compareActivities);
  int lastFinished = activities[0].finish;
  int count = 1;

  for (int i = 1; i < n; ++i) {
    if (activities[i].start >= lastFinished) {
      lastFinished = activities[i].finish;
      count++;
    }
  }

  return count;
}

int main() {
int n;
  cin >> n;

  vector<Activity> activities(n);
  for (int i = 0; i < n; ++i) {
    cin >> activities[i].start;
  }
  for (int i = 0; i < n; ++i) {
    cin >> activities[i].finish;
  }
  int maxActivities = selectMaxActivities(activities);
  cout << "\nMaximum number of non-conflicting activities: " << maxActivities << endl;
  return 0;
}
