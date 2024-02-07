#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
  int answer = 0;
  queue<int> q;
  for (int i = 0; i < section.size(); i++) q.push(section[i]);
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    while (!q.empty() && q.front() < front + m) q.pop();
    answer++;
  }
  return answer;
}

int main() {
  int n, m;
  vector<int> section;
  n = 8, m = 4;
  section = {2, 3, 6};
  int result = solution(n, m, section);
  cout << result << " == 2" << endl;
  n = 5, m = 4;
  section = {1, 3};
  result = solution(n, m, section);
  cout << result << " == 1" << endl;
  n = 4, m = 1;
  section = {1, 2, 3, 4};
  result = solution(n, m, section);
  cout << result << " == 4" << endl;
}
