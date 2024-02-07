#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
  int answer = 0;
  sort(dungeons.begin(), dungeons.end());
  do {
    int init = k;
    int count = 0;
    for (const auto& dungeon : dungeons) {
      if (init >= dungeon[0]) {
        init -= dungeon[1];
        count++;
      } else {
        break;
      }
    }
    answer = max(answer, count);
  } while (next_permutation(dungeons.begin(), dungeons.end()));
  return answer;
}

int main() {
  int k = 80;
  vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};
  cout << solution(k, dungeons) << " == 3" << endl;
}
