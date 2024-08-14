#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int cost[25][305];
int cache[25][305];

int main(){
    fastio;
    cin >> N >> M;
    int a,b;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        for (int j = 1; j <= M; j++)
        {            
            cin >> cost[j][a];
        }
        
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = N; j >=  0; j--)
        {
            cache[i][j] = max(cache[i][j], cache[i-1][N-j] + cost[i][j]);
        }        
    }
    vector<int> trace(N+1);
    int idx = M;
    int cur = cache[M][N];
    while (idx > 0)
    {
        for (int j = N; j >= 0; j--)
        {
            if(cur == cache[idx-1][N-j] + cost[idx][j]){
                trace[idx] = j;
                cur -= cost[idx][j];
                break;
            }
        }        
        idx--;
    }
            
    cout << cache[M][N] << '\n';
    for (int i = 1; i <= M; i++)
    {
        cout << trace[i] << ' ';
    }
    
    return 0;
}