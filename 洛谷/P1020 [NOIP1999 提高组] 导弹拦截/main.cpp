#include <bits/stdc++.h>
using namespace std;
int longestDecreasingSubsequence(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] >= heights[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxLength = 0;
    for (int length : dp) {
        maxLength = max(maxLength, length);
    }
    return maxLength;
}

int minimumNumberOfSystems(vector<int>& heights) {
    vector<int> tails;

    for (int height : heights) {
        auto pos = upper_bound(tails.begin(), tails.end(), height);
        if (pos != tails.end()) {
            *pos = height;
        } else {
            tails.push_back(height);
        }
    }
    return tails.size();
}

int main() {
    int a;
    vector<int> heights;
    while (cin>>a)
    {
        heights.push_back;
    }
    
    cout << longestDecreasingSubsequence(heights) << endl;
    cout << minimumNumberOfSystems(heights) << endl;
}
