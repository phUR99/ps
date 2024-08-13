#include <string>
#include <vector>
#include <queue>
using namespace std;
int arr[6];
int answer = 987654321;

struct node{
    int cost;
    const bool operator<(const node &a) const{
        return a.cost < cost;
    }
};

int sol(vector<vector<int>> &reqs){
    int ret = 0;
    priority_queue<node> pq[6];
    for (auto i : reqs){
        int start = i[0];
        int demand = i[1];
        int type = i[2];
        if(pq[type].size() < arr[type]) pq[type].push({start+demand});
        else{
            int nxt = max(0, pq[type].top().cost - start); 
            ret += nxt;            
            pq[type].pop();
            pq[type].push({start + demand + nxt});            
        }
    }
    return ret;
}
void func(int n, int k, vector<vector<int>> &reqs){
    if(k == 0){
        answer = min(answer, sol(reqs));
        return;           
    }    
    for (int i = 1; i <= n - (k -1); i++){
        arr[k] = i;
        func(n-i, k-1, reqs);
    }
}


int solution(int k, int n, vector<vector<int>> reqs) {
    func(n, k, reqs);
    
    return answer;
}