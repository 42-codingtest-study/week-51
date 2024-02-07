#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
  for (int i = 1; i <= n; ++i) cost[i][i] = 0;
  for (auto& fare : fares)
    cost[fare[0]][fare[1]] = fare[2], cost[fare[1]][fare[0]] = fare[2];
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (cost[i][k] + cost[k][j] < cost[i][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }
  int minCost = INF;
  for (int i = 1; i <= n; ++i) {
    if (cost[s][i] != INF && cost[i][a] != INF && cost[i][b] != INF) {
      int totalCost = cost[s][i] + cost[i][a] + cost[i][b];
      if (totalCost < minCost) {
        minCost = totalCost;
      }
    }
  }
  return minCost;
}

int main() {
  int n = 6, s = 4, a = 6, b = 2;
  vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2},
                               {3, 1, 41}, {5, 1, 24}, {4, 6, 50},
                               {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
  int result = solution(n, s, a, b, fares);
  cout << result << " == 82" << endl;
  n = 7, s = 3, a = 4, b = 1;
  fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
  result = solution(n, s, a, b, fares);
  cout << result << " == 14" << endl;
  n = 6, s = 4, a = 5, b = 6;
  fares = {{2, 6, 6},  {6, 3, 7},  {4, 6, 7}, {6, 5, 11},
           {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}};
  result = solution(n, s, a, b, fares);
  cout << result << " == 18" << endl;
}
