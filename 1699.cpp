#include <iostream>
#include <string.h>
using namespace std;

int cache[100005];
int N;
const int NOT = 987654321;

int findminValue(int n){
    if(n == 0) return 0;
    else if(n < 0) return NOT;

    int &ret = cache[n];
    if (ret != -1) return ret;
    ret = NOT;
    for (int i = 1; i*i <= N; i++)
    {
        ret = min(ret, findminValue(n-i*i)+1);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(cache, -1, sizeof(cache));

    cout << findminValue(N);

    return 0;
}