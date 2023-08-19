#include <bits/stdc++.h>

using namespace std;

#define dbg(x) std::cout<<#x<<"="<<x<<"\n";
#define dbgg(x,y) std::cout<<#x<<"="<<x<<","<<#y<<"="<<y<<"\n";
#define dbggg(x,y,z) std::cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<"\n";

using namespace std;

#define FOR(p,q,r) for(int i = p; i != q; i+=r)
#define FORE(n) for(auto &i : n)
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

void combination(vector<vector<int>> &ans, vector<int> &currComb, const vector<int> &candidates, int target, size_t currIndex, int currSum) {
  if(currSum > target) return;
  if(currSum == target) {
    ans.push_back(currComb);
    return;
  }
  for(size_t i = currIndex; i<candidates.size(); i++) {
    if(i > currIndex && candidates[i]==candidates[i-1])
      continue;
    if(candidates[i] > target)
      break;
    currComb.push_back(candidates[i]);
    combination(ans, currComb, candidates, target, i+1, currSum+candidates[i]);
    currComb.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<vector<int>> ans;
  vector<int> currComb;
  sort(candidates.begin(), candidates.end());
  combination(ans, currComb, candidates, target, 0, 0);
  return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vi in{10,1,2,7,6,1,5};
  vector<vector<int>> ans = combinationSum2(in, 8);
  for(auto i: ans) {
    print_vec(i);
  }
  return 0;
}
