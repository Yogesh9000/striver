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

void subset_sum(si &ans,vi input, vi output) {
    if(input.empty())
        ans.insert(accumulate(output.begin(), output.end(),0));
    else {
        int val = input[input.size() - 1];
        input.pop_back();
        output.push_back(val);
        subset_sum(ans, input, output);
        output.pop_back();
        subset_sum(ans, input, output);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    si ans;
    vi output;
    vi input{5,2,1};
    subset_sum(ans, input, output);
    for(auto i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
