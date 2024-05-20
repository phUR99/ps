#include <bits/stdc++.h>
using namespace std;
const int NOT = 987654321;

/*
틀린 이유
1. rx, ry의 위치에만 제한을 걸어서 rx, ry가 같고, bx, by가 다른 상황을 전부 제한을 걸어버렸음 -> 반례 존재, 제한을 더 빡빡하게
2. 4차원 배열을 불 자료형으로 사용해서 생기는 문제 -> 가는 거리가 더 짧아도 가지 못하는 상황, 불을 int형으로 대체하고 dist 형식으로 짜기
*/

char table[12][12];

int visited[12][12][12][12];

int N, M;

int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, -1, 1};

int Rx, Ry, Bx, By;
int ans = NOT;

void func(int Rx, int Ry, int Bx, int By, int cnt){


    for (int dir = 0; dir < 4; dir++)
    {
        int cur_rx = Rx;
        int cur_ry = Ry;
        int cur_bx = Bx;
        int cur_by = By;

        int dist_r =0, dist_b = 0;
        bool flag = false;

        while (table[cur_bx+dx[dir]][cur_by+dy[dir]] != '#')
        {
            if(table[cur_bx+dx[dir]][cur_by+dy[dir]] == 'O') {
                flag = true;
                break;
            }         
            cur_bx += dx[dir];
            cur_by += dy[dir];
            dist_b++;
        }
        if (flag) continue;

        while (table[cur_rx+dx[dir]][cur_ry+dy[dir]] != '#')
        {
            if(table[cur_rx+dx[dir]][cur_ry+dy[dir]] == 'O'){
                ans = min(ans, cnt);
                return;
            }
            cur_rx += dx[dir];
            cur_ry += dy[dir];
            dist_r++;
        }
        if(cur_bx == cur_rx && cur_by == cur_ry){
            if(dist_b > dist_r){
                cur_bx -= dx[dir];
                cur_by -= dy[dir];
            }
            else{
                cur_rx -= dx[dir];
                cur_ry -= dy[dir];
            }
        }
        if(visited[cur_rx][cur_ry][cur_bx][cur_by] != -1 && visited[cur_rx][cur_ry][cur_bx][cur_by] <= cnt) continue;     
        visited[cur_rx][cur_ry][cur_bx][cur_by] = cnt;
        func(cur_rx, cur_ry, cur_bx, cur_by, cnt +1);

    }
   
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            cin >> table[i][j];
            if(table[i][j] == 'R') {
                Rx = i;
                Ry = j;
            }
            else if (table[i][j] == 'B'){
                Bx = i;
                By = j;
            }
        }
    }
    visited[Rx][Ry][Bx][By] = 0;

    func(Rx, Ry, Bx, By, 1);      
    cout << (ans = (ans == NOT) ? -1 : ans);
    

    return 0;
}