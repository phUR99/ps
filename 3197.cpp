#include <bits/stdc++.h>
using namespace std;
int R, C;
char board[1505][1505];
pair<int, int> st, ed;
const int WALL = 987654321;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1 ,1};
int dist[1505][1505];
bool visited[1505][1505];
/*
maxDist를 선언하고 이를 바탕으로 BFS를 돌리는 것은 실패... R과 C가 어느정도 큰 상태에서 BFS를 계속 돌림으로싸 시간초과 발생
DFS를 한번만 돌릴 수 있는 아이디어... 우선순위 큐를 이용해서 거리의 오름차순으로 노드를 넣는 발상

*/

//오름차순 우선순위 큐를 선언하고 싶을 때 유리한 구조체 선언
struct node
{
    int d, x, y;
    const bool operator<(const node &a) const{
        return a.d < d;
    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    st.first = -1;
    queue<pair<int, int>> q;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {            
            cin >> board[i][j];
            if (board[i][j] == '.'){
                dist[i][j] = 0;
                q.push({i, j});
            }
            else if (board[i][j] == 'L' && st.first == -1){
                dist[i][j] = 0;
                st.first= i;
                st.second = j;
                q.push({i, j});
            }
            else if (board[i][j] == 'L' && st.first != -1){
                dist[i][j] = 0;
                ed.first= i;
                ed.second = j;
                q.push({i, j});
            }
            else{
                dist[i][j] = WALL;
            }
        }
        
    }

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();        
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= R || ny <0 || ny >= C) continue;
            if(dist[nx][ny] <= dist[cur.first][cur.second] + 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;            
            q.push({nx, ny});

        }        
    }    
    priority_queue<node> pq;

    visited[st.first][st.second] = true;
    pq.push({0, st.first, st.second});
    int ans = 0;

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        ans = max(ans, cur.d);
        if(cur.x == ed.first && cur.y == ed.second){
            cout << ans;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= R || ny <0 || ny >= C) continue;
            if(visited[nx][ny]) continue;                        
            pq.push({dist[nx][ny], nx, ny});
            visited[nx][ny] = true;                        
        }    
    }
    return 0;
}