#include <bits/stdc++.h>

#define dbg(x) std::cout << #x << "=" << x << "\n";
#define dbgg(x, y) std::cout << #x << "=" << x << "," << #y << "=" << y << "\n";
#define dbggg(x, y, z)                                                         \
  std::cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "="     \
            << z << "\n";

using namespace std;

#define FOR(p, q, r) for (int i = p; i != q; i += r)
#define FORE(n) for (auto &i : n)
#define vi vector<int>
#define si set<int>
#define usi unordered_set<int>
#define mi multiset<int>
#define umi unordered_multiset<int>
#define pii pair<int, int>
#define ln "\n"
#define ll long long

void print_vec(const vi &v) {
    for(auto i: v) {
        cout<<i<<" ";
    }
    cout<<ln;
}

void combination(vector<vector<int>> &ans, vector<int> &currComb, vi &candidates,
                 int target, size_t currIndex, int currSum) {
  if (currSum > target)
    return;
  if (currSum == target) {
    ans.push_back(currComb);
    return;
  }
  for (size_t i = currIndex; i < candidates.size(); i++) {
    currComb.push_back(candidates[i]);
    combination(ans, currComb, candidates, target, i, currSum+candidates[i]);
    currComb.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vi> ans;
  vector<int> currComb;
  combination(ans, currComb, candidates, target, 0, 0);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vi c{2, 3, 6, 7};
  int t = 7;
  vector<vi> ans = combinationSum(c, t);
  for(auto i: ans) {
      print_vec(i);
  }
  return 0;
}
