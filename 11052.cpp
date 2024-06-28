#include <iostream>
#include <string.h>
using namespace std;


int P[1005];
int N;
const int NOT = -987654321;
int cache[10005];

int func(int n){
    if (n == 0) return 0;
    else if(n < 0) return NOT;

    int &ret = cache[n];
    if(ret != -1) return ret;
    ret = NOT;

    for (int i = 1; i <= N; i++)
    {
        ret = max(ret, func(n-i)+P[i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }
    cout << func(N);

    return 0;
}
