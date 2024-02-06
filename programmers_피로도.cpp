#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int maxval = -1;

int solution(int k, vector<vector<int>> dungeons)
{
  int answer = -1;

  sort(dungeons.begin(), dungeons.end());

  do
  {
    int cnt = 0;
    int tmp_k;
    tmp_k = k;

    for (int i = 0; i < dungeons.size(); i++)
    {
      if (tmp_k >= dungeons[i][0])
      {
        tmp_k -= dungeons[i][1];
        cnt++;
      }
      else
      {
        break;
      }
    }

    maxval = max(maxval, cnt);

  } while (next_permutation(dungeons.begin(), dungeons.end()));

  return maxval;
}