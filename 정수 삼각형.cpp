#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
  int answer = 0;
  vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
  dp[0][0] = triangle[0][0];
  for (int i = 1; i < triangle.size(); i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] + triangle[i][j];
      } else if (j == i) {
        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
      } else {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }
    }
  }
  for (int i = 0; i < triangle.size(); i++) {
    answer = max(answer, dp[triangle.size() - 1][i]);
  }
  return answer;
}

int main() {
  vector<vector<int>> triangle = {
      {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
  int result = solution(triangle);
  cout << result << " == 30" << endl;
  return 0;
}
