#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXL	5
#define MAXF	10

std::unordered_set<int> adj[10001];
int num[10001];

struct node
{
    int num, id;
    const bool operator<(const node & a) const{
        if(num == a.num) return a.id <id;
        return num < a.num;
    }
};

int SIZE;
void init(int N)
{
    SIZE = N;
	for (int i = 0; i < N+1; i++)
    {
        adj[i].clear();
    }    
}

void add(int id, int F, int ids[MAXF])
{
    for (int i = 0; i < F; i++)
    {
        adj[id].insert(ids[i]);
        adj[ids[i]].insert(id);
    }    
}

void del(int id1, int id2)
{
    adj[id1].erase(adj[id1].find(id2));
    adj[id2].erase(adj[id2].find(id1));
}

int recommend(int id, int list[MAXL])
{
    std::priority_queue<node> pq;
    std::fill(num, num+SIZE+1, 0);

    for (auto child : adj[id])
    {        
        for (auto nxt : adj[child])
        {            
            if(nxt == id) continue;
            if(adj[id].find(nxt) != adj[id].end()) continue;
            num[nxt]++;
        }        
    }
    for (int i = 0; i < SIZE + 1; i++)
    {
        if(num[i] == 0) continue;
        pq.push({num[i], i});
    }    
    int idx = 0;
    while (!pq.empty() && idx < MAXL)
    {         
        list[idx] = pq.top().id; pq.pop();
        idx++;
    }        
	return idx;
}