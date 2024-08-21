#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int n, W;

int arr[5005];
bool cache[400050];
/*
n^4를 n^2로 줄이는 아이디어까지는 생각했는데..
인덱스 4개의 운용을 2개의 반복문으로 처리할 수 있다는 것을 배웠음.
*/

int main()
{
    fastio;
    cin >> W >> n;
    memset(cache, false, sizeof(cache));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] + arr[j] >= W)
                break;
            cache[arr[i] + arr[j]] = true;
        }
        for (int j = i + 2; j < n; j++)
        {
            if (W - arr[i + 1] - arr[j] > 400000 || W - arr[i + 1] - arr[j] <= 0)
                break;
            if (cache[W - arr[i + 1] - arr[j]])
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}