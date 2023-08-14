#include <bits/stdc++.h>

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

void subset(set<vector<int>> &s, vector<int> nums, vector<int> output) {
    if(nums.empty()) {
        sort(output.begin(), output.end());
        s.insert(output);
    }
    else {
        int val = nums[nums.size()-1];
        nums.pop_back();
        output.push_back(val);
        subset(s, nums, output);
        output.pop_back();
        subset(s, nums, output);
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> s;
    vector<int> output;
    vector<vector<int>> ans;
    subset(s, nums, output);
    for(auto i: s) {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums{1,2,2};
    vector<vector<int>> output = subsetsWithDup(nums);
    for(auto i: output) {
        for(auto j:i) {
            std::cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
