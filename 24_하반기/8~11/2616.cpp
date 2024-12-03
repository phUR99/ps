#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int pSum[50050];
int cache[4][50050];

int n, k;

int main(){
    fastio;
    int cur;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        pSum[i] = pSum[i-1] + cur;
    }
    cin >> k;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = k; j <= n; j++)
        {
            cache[i][j] = max(cache[i][j-1], cache[i-1][j-k]+ pSum[j]-pSum[j-k]);
        }
        
    }
    cout << cache[3][n];

    return 0;
}