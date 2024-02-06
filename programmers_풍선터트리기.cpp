#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

vector<pair<int, int>> arr;
vector<int> leftMin(1000002);
vector<int> rightMin(1000002);

int solution(vector<int> a)
{
  int answer = 0;

  leftMin[0] = a[0];
  for (int i = 1; i < a.size(); i++)
  {
    leftMin[i] = min(leftMin[i - 1], a[i]);
  }

  rightMin[a.size() - 1] = a[a.size() - 1];
  for (int i = a.size() - 2; i > 0; i--)
  {
    rightMin[i] = min(rightMin[i + 1], a[i]);
  }

  for (int i = 1; i < a.size() - 1; i++)
  {
    if (a[i] < leftMin[i - 1] || a[i] < rightMin[i + 1])
      answer++;
  }
  return answer + 2;
}