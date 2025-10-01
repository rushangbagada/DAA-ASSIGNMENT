#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector
#define vll vector<ll>
#define vint vector<int>

void print_paren (vector<vint>& split, int i, int j) 
    {
        if (i == j) {
            cout << "A" << i;
            return;
        }
        cout << "(";
        int k = split[i][j];
        print_paren(split,i,k);
        print_paren(split,k+1,j);
        cout << ")";
    }

void matrix_chain_multiplication(const vll &p)
{
    int n = p.size() - 1; 
    v<vll> dp(n, vll(n, 0));
    v<vint> split(n, vint(n, -1));

    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i< n-len-1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for (int k=i; k<j; k++) 
            {
                
                ll cost = dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j+1];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum cost: " << dp[0][n-1] << "\n";
    cout << "Optimal Parenthesization: ";

    
    

    print_paren(split,0, n-1);
    cout << endl;
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
        cin >> x;
        vll a(x);

        for(ll i = 0; i < x; i++)
        {
            cin >> a[i];
        }

        matrix_chain_multiplication(a);
    }
    return 0;
}