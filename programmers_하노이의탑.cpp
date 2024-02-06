#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void hanoi(int n, int from, int by, int to)
{
  if (n == 1)
  {
    vector<int> tmp;
    tmp.push_back(from);
    tmp.push_back(to);
    ans.push_back(tmp);
  }
  else
  {
    hanoi(n - 1, from, to, by);
    vector<int> tmp;
    tmp.push_back(from);
    tmp.push_back(to);
    ans.push_back(tmp);
    hanoi(n - 1, by, from, to);
  }
}

vector<vector<int>> solution(int n)
{
  vector<vector<int>> answer;
  hanoi(n, 1, 2, 3);
  return ans;
}