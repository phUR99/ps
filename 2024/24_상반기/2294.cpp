#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int arr[105];
int N, K;
int cache[10005];
const int NOT = 987654321;

int func(int k){
    if(k == 0) return 0;
    else if (k < 0) return NOT;

    int &ret = cache[k];
    if(ret != -1) return ret;
    ret = NOT;

    for (int i = 0; i < N; i++)
    {
        ret = min(ret, func(k-arr[i])+1);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << (func(K) == NOT ? -1 : func(K));
    return 0;
}
