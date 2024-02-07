#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

deque<pair<int, int>> indexingAndSorting(vector<int> a) {
  deque<pair<int, int>> result;
  for (int i = 0; i < a.size(); i++) result.push_back({a[i], i});
  sort(result.begin(), result.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) {
         return x.first < y.first;
       });
  return result;
}

int solution(vector<int> a) {
  deque<pair<int, int>> sorted = indexingAndSorting(a);
  int answer = 2, left = a[0],
      right = (sorted[0].second != 0) ? sorted[0].first : sorted[1].first,
      leftIndex = 0,
      rightIndex =
          (sorted[0].second != 0) ? sorted[0].second : sorted[1].second;
  if (a.size() == 1) return 1;
  if (sorted[0].second != 0)
    sorted.pop_front();
  else
    sorted.pop_front(), sorted.pop_front();
  for (int i = 1; i < a.size() - 1; i++) {
    if (right > a[i] || left > a[i]) answer++;
    if (left > a[i]) left = a[i], leftIndex = i;
    while (i >= rightIndex - 1) {
      if (sorted.size() == 0) break;
      if (sorted[0].second <= rightIndex) {
        sorted.pop_front();
        continue;
      }
      right = sorted[0].first;
      rightIndex = sorted[0].second;
      sorted.pop_front();
    }
  }
  return answer;
}

int main() {
  vector<int> a = {9, -1, -5};
  cout << solution(a) << " == 3" << endl;
  vector<int> b = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
  cout << solution(b) << " == 6" << endl;
}
