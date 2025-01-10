#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
정해 1
소수 = 짝수 + 홀수 형태만 가능하므로 한쪽 그래프에는 짝수, 한쪽 그래프에는 홀수를 저장

현재 그래프가 암묵적으로 이분 그래프의 형태를 띔(짝수 - 홀수)
분리하지 않아도 해결 가능
*/
#define MX 2000
bool isPrime[MX + 5];
bool adj[55][55];
int n;
void precalc()
{
    fill(isPrime, isPrime + MX + 5, 1);
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i * i <= MX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MX; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
vector<int> aMatch, bMatch;
vector<bool> visited;
int chosen;
bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 1; b < n; b++)
    {
        if (b == chosen)
            continue;
        if (adj[a][b])
        {
            if (bMatch[b] == -1 || dfs(bMatch[b]))
            {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}
bool bipartiteMatch(int f)
{
    chosen = f;
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(n, -1);
    int size = 2;
    for (int start = 1; start < n; start++)
    {
        if (start == chosen)
            continue;
        visited = vector<bool>(n, false);
        if (dfs(start))
            size++;
    }
    return size == n;
}

int main()
{
    fastio;

    precalc();
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPrime[arr[i] + arr[j]])
            {
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    vector<int> ret;
    for (int i = 1; i < n; i++)
    {
        if (adj[0][i] && bipartiteMatch(i))
            ret.push_back(arr[i]);
    }
    sort(ret.begin(), ret.end());
    if (ret.size())
    {
        for (auto r : ret)
        {
            cout << r << ' ';
        }
    }
    else
        cout << -1;

    return 0;
}