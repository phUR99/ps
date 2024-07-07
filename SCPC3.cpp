
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long Answer;
vector<int> adj[300005];
int num[300005];
long long dist[300005];
vector<int> three;

int main(int argc, char** argv)
{
	int T, test_case;
    long long N;
    fastio;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
        Answer = 0;
        for (int i = 1; i <= N; i++)
        {
            adj[i].clear();
            num[i]= 0;
        }
        for (int i = 0; i <= N; i++)
        {
            int u, v;
            cin >> u >> v; 
            adj[u].push_back(v);
            adj[v].push_back(u);
            num[u]++;
            num[v]++;
        }
        three.clear();        
   		for (int i = 1; i <= N; i++)
        {
            if(num[i] == 3) three.push_back(i);
        }
        int st = three[0];
        int ed = three[1];
        memset(dist, -1, sizeof(dist));
        dist[st] = 0;
        queue<int> q;
        for (auto child : adj[st])
        {
            if(child == ed) continue;
            q.push(child);
            dist[child] = dist[st] +1;
        }
        while (!q.empty())
        {
            int node = q.front(); q.pop();
            for (auto child : adj[node])
            {
                if(dist[child] != -1) continue;
                dist[child] = dist[node] + 1;
                q.push(child);  
            }            
        }
        Answer = N * (N - 1) /2 - dist[ed] * (N - dist[ed]);
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}