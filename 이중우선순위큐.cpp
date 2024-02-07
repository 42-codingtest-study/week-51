#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
  multiset<int> dq;
  vector<int> answer;
  for (const auto& op : operations) {
    if (op[0] == 'I')
      dq.insert(stoi(op.substr(2)));
    else if (!dq.empty())
      dq.erase((op[2] == '1') ? prev(dq.end()) : dq.begin());
  }
  if (dq.empty())
    answer.push_back(0), answer.push_back(0);
  else
    answer.push_back(*dq.rbegin()), answer.push_back(*dq.begin());
  return answer;
}

int main() {
  vector<string> operations = {"I 16", "I -5643", "D -1", "D 1",
                               "D 1",  "I 123",   "D -1"};
  vector<int> result = solution(operations);
  cout << result[0] << " == 0" << endl;
  cout << result[1] << " == 0" << endl;
  operations = {"I -45", "I 653", "D 1",  "I -642", "I 45",
                "I 97",  "D 1",   "D -1", "I 333"};
  result = solution(operations);
  cout << result[0] << " == 333" << endl;
  cout << result[1] << " == -45" << endl;
}
