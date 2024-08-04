#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int W, N;
int arr[5005];
int main(){
    fastio;
    cin >> W >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    deque<int> dq;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum +=arr[i];
        if(sum == W){
            cout << "YES";
            return 0;
        }
    }
    for (int i = 4; i < N; i++)
    {
        sum -= arr[i-4];
        sum += arr[i];
        if(sum == W){
            cout << "YES";
            return 0;
        }
        
    }
    cout << "NO";
    

    return 0;
}