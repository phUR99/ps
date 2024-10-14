/*
타잔 알고리즘
1. 방문할 때마다 stack에 방문 정점을 저장
2. 방문 가능한 최소 정점을 찾은 후 stack을 pop하면서
자신의 번호가 등장할 때까지 찾음
-> stack에서 나온 정점은 모두 SCC

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Vertex[20002];
int SCCnum[20002];
stack<int> stk;
int discovered[20002];

int sccCounter, vertexCounter;

int SCC(int now)
{
    int ret = discovered[now] = vertexCounter++;
    stk.push(now);

    for (int i = 0; i < Vertex[now].size(); i++)
    {
        int next = Vertex[now][i];

        if (discovered[next] == -1)
        {
            ret = min(ret, SCC(next));
        }
        else if (SCCnum[next] == -1)
        {
            ret = min(ret, discovered[next]);
        }
    }

    if (ret == discovered[now])
    {
        while (true)
        {
            int temp = stk.top();
            stk.pop();
            SCCnum[temp] = sccCounter;
            if (temp == now)
                break;
        }
        sccCounter++;
    }

    return ret;
}
