#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Task {
  int time;
  int deadline;
};

bool compareTasks(const Task& a, const Task& b) {
  return (double)a.time / a.deadline > (double)b.time / b.deadline;
}

int scheduleTasks(vector<Task>& tasks) {
  int n = tasks.size();
  if (n == 0) {
    return 0;
  }

  sort(tasks.begin(), tasks.end(), compareTasks);

  int currentTime = 0;
  int count = 0;

  for (Task task : tasks) {
    if (currentTime <= task.deadline) {
      currentTime += task.time;
      count++;
    }
  }

  return count;
}

int main() {
  int n;
  cout << "Enter the total number of tasks (N): ";
  cin >> n;

  vector<Task> tasks(n);

  cout << "Enter the time taken for each task (space-separated): ";
  for (int i = 0; i < n; ++i) {
    cin >> tasks[i].time;
  }
  cout << "Enter the deadline for each task (space-separated): ";
  for (int i = 0; i < n; ++i) {
    cin >> tasks[i].deadline;
  }

  int maxTasks = scheduleTasks(tasks);
  cout << "\nMaximum number of tasks that can be completed: " << maxTasks << endl;
  return 0;
}

