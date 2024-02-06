#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> golds;

int main(int argc, char **argv)
{
  int w, n;
  cin >> w >> n;

  for (int i = 0; i < n; i++)
  {
    int m, p;
    cin >> m >> p;
    golds.push_back(make_pair(p, m));
  }
  sort(golds.begin(), golds.end(), greater<>());
  // 가격, 무게
  long long price = 0;
  for (int i = 0; i < n; i++)
  {
    // cout<<"i is " << i << "\n";
    if (w == 0)
    {

      cout << price << "\n";
      return 0;
    }
    if (golds[i].second >= w)
    {
      price += golds[i].first * w;
      w = 0;
    }
    else
    {
      price += golds[i].first * golds[i].second;
      w -= golds[i].second;
    }
  }
  cout << price << "\n";

  return 0;
}