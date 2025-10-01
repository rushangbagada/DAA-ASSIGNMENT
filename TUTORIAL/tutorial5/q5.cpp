#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector
#define vll vector<ll>
#define vint vector<int>

void helper(vll &a)
{
    ll n = a.size();
    vll dp(n,0);

    for(ll i = 1; i < n; i++)
    {
        ll cost = LLONG_MIN;
        for(ll j = 0; j < i; j++)
        {
            cost=max(cost,a[j]+dp[i-j-1]);
        }
        dp[i] = cost;
    }

    cout << dp[n-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    while(n--)
    {
        ll x;
        cin >> x ;
        vll a(x);

        for(ll i = 0; i < x; i++)
        {
            cin >> a[i];
        }

        helper(a);
        cout << endl;
    }
    return 0;
}