#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int G, P, g;
int parent[100005];
/*
idea : 남아있는 게이트에 도킹하는 것이 최대의 해를 보장한다...
->더 작은 게이트에 도킹해서 최댓값이 생길 수 있나? X
따라서, union_find를 이용해서 사용한 게이트를 묶어주고, 시작하는 게이트를 표시하기
시작하는 게이트가 0이면? 더 이상 도킹 불가능
*/

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void uni(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(u > v) swap(u, v);
    parent[v] = u;
}

int main(){
    fastio;
    cin >> G >> P;
    int answer = 0;
    for(int i = 0; i <= G; i++) parent[i] = i;
    for(int p = 0; p < P; p++)
    {
        cin >> g;
        g = find(g);        
        if(g == 0) break;
        answer = p + 1;
        uni(g, g-1);
    }
    cout << answer;


    return 0;
}