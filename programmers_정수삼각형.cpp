// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// vector<vector<int>> tmp;
// vector<vector<int>> memo;

// int max_val = -1;

// void dp_func(int index, int garo, int sum, vector<vector<int>> triangle)
// {
//     if (index == triangle.size() - 1)
//     {
//         if (max_val < sum + triangle[index][garo])
//             max_val = sum + triangle[index][garo];
//         return;
//     }

//     if (memo[index][garo] != -1)
//     {
//         if (max_val < sum + memo[index][garo]) {
//             max_val = sum + memo[index][garo];
//         }
//         return;
//     }

//     dp_func(index+1, garo, sum+triangle[index][garo], triangle);
//     dp_func(index+1, garo+1, sum+triangle[index][garo], triangle);

//     return;
// }
// int solution(vector<vector<int>> triangle) {
//     int answer = 0;

//     memo.assign(triangle.size(), vector<int>(triangle.size(), -1));

//     dp_func(0, 0, 0, triangle);

//     return max_val;
// }

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
  int answer = 0;

  int length = triangle.size() - 1;
  int dp[501][501];
  dp[0][0] = triangle[0][0];

  for (int i = 1; i <= length; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else if (j == i)
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
      }
      dp[i][j] += triangle[i][j];
    }
  }

  answer = dp[length][0];
  for (int i = 1; i <= length; i++)
  {
    if (dp[length][i] > answer)
    {
      answer = dp[length][i];
    }
  }

  return answer;
}
