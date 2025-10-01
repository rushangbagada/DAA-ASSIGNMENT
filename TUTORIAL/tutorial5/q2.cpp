#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector
#define vll vector<ll>
#define vint vector<int>

void helper(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=0;i<=m;i++)
    {
        dp[i][0] = n-i+1; // deletion
    }
    for(int j=0;j<=n;j++)
    {
        dp[0][j] = m-j+1; // insertion
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    cout << dp[m][n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    while(n--)
    {
        string s1,s2;

        cin >> s1 >> s2;

        helper(s1,s2);

        cout << endl;
    }

    return 0;
}