#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define X first 
#define Y second

using namespace std;

int b[5][5];
int p[3][3];
int Limit;
bool fix[5][5];
int dist[5][5];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<pair<int, int>> position;
vector<int> path;
pair<int, int> prevPath[5][5];
pair<int, int> zero;
void initZero(){
    for (int i =0; i < 5; i++){
        for (int j = 0; j < 5; j++)
        {
            if(b[i][j] == 0){
                zero = {i, j};
                return;
            }
        }        
    }
}
void copyBoard(int board[5][5]){
    for (int i =0; i < 5; i++){
        for (int j = 0; j < 5; j++)
        {
            b[i][j] = board[i][j];
        }        
    }
}

extern bool swap(int dir);
/*
void printBoard(){
    for (int i =0; i < 5; i++){
        for (int j = 0; j < 5; j++)
        {
            cout << b[i][j] << ' ';
        }        
        cout << '\n';
    }
    cout << '\n';
}
*/
bool match(){
    for (int i =0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            if(b[i+1][j+1] != p[i][j])  return false;
        }        
    }
    return true;
}

void moveZero(vector<pair<int, int>> & track){    
    vector<pair<int, int>> trackZero;
    
    for (int i = 1; i < track.size(); i++)
    {        
        if(track[i].X == zero.X && track[i].Y  == zero.Y){            
            int nx = track[i-1].X - track[i].X;
            int ny = track[i-1].Y - track[i].Y;                    
            int tmp;
            if(nx == 1){
                path.push_back(DOWN);     
                tmp = b[track[i].X][track[i].Y];
                b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                b[track[i-1].X][track[i-1].Y] = tmp;                                                        
            }
            else if(nx == -1){
                path.push_back(UP);
                tmp = b[track[i].X][track[i].Y];
                b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                b[track[i-1].X][track[i-1].Y] = tmp;                                                        
            }
            else if(ny == 1){
                path.push_back(RIGHT);
                tmp = b[track[i].X][track[i].Y];
                b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                b[track[i-1].X][track[i-1].Y] = tmp;                                                        
            }
            else if(ny == -1){
                path.push_back(LEFT);
                tmp = b[track[i].X][track[i].Y];
                b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                b[track[i-1].X][track[i-1].Y] = tmp;                                                        
            } 
        }
        memset(dist, -1, sizeof(dist));
        queue<pair<int, int>> q;
        initZero();      
        trackZero.clear();
        q.push(zero);                
        dist[zero.X][zero.Y] = 0;
        bool isDone = false;        

        while (!q.empty())
        {

            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];                
                if(nx <0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(dist[nx][ny] != -1 || fix[nx][ny] || (nx == track[i-1].X && ny ==track[i-1].Y)) continue;
                prevPath[nx][ny] = {cur.X, cur.Y};
                if(nx == track[i].X && ny == track[i].Y){                    
                    while (!(nx == zero.X && ny == zero.Y))
                    {
                        trackZero.push_back({nx, ny});
                        int tx = prevPath[nx][ny].X;
                        int ty = prevPath[nx][ny].Y;
                        nx = tx;
                        ny = ty;                        
                    }
                    trackZero.push_back({zero.X, zero.Y});
                    reverse(trackZero.begin(), trackZero.end());                    
                    for (int j = 1; j < trackZero.size(); j++)
                    {
                        int nx = trackZero[j].X - trackZero[j-1].X;
                        int ny = trackZero[j].Y - trackZero[j-1].Y;
                        int tmp;
                        if(nx == 1){
                            path.push_back(DOWN);                    
                            tmp = b[trackZero[j].X][trackZero[j].Y];
                            b[trackZero[j].X][trackZero[j].Y] = b[trackZero[j-1].X][trackZero[j-1].Y];
                            b[trackZero[j-1].X][trackZero[j-1].Y] = tmp;                                                        
                        }
                        else if(nx == -1){
                            path.push_back(UP);                        
                            tmp = b[trackZero[j].X][trackZero[j].Y];
                            b[trackZero[j].X][trackZero[j].Y] = b[trackZero[j-1].X][trackZero[j-1].Y];
                            b[trackZero[j-1].X][trackZero[j-1].Y] = tmp;
                        }
                        else if(ny == 1){
                            path.push_back(RIGHT);
                            tmp = b[trackZero[j].X][trackZero[j].Y];
                            b[trackZero[j].X][trackZero[j].Y] = b[trackZero[j-1].X][trackZero[j-1].Y];
                            b[trackZero[j-1].X][trackZero[j-1].Y] = tmp;
                        }
                        else if(ny == -1){
                            path.push_back(LEFT);
                            tmp = b[trackZero[j].X][trackZero[j].Y];
                            b[trackZero[j].X][trackZero[j].Y] = b[trackZero[j-1].X][trackZero[j-1].Y];
                            b[trackZero[j-1].X][trackZero[j-1].Y] = tmp;
                        }                                
                    }        
                    int nx = track[i-1].X - track[i].X;
                    int ny = track[i-1].Y - track[i].Y;                    
                    int tmp;
                    if(nx == 1){
                        path.push_back(DOWN);     
                        tmp = b[track[i].X][track[i].Y];
                        b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                        b[track[i-1].X][track[i-1].Y] = tmp;                                                        
                    }
                    else if(nx == -1){
                        path.push_back(UP);
                        tmp = b[track[i].X][track[i].Y];
                        b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                        b[track[i-1].X][track[i-1].Y] = tmp;                                                        
                    }
                    else if(ny == 1){
                        path.push_back(RIGHT);
                        tmp = b[track[i].X][track[i].Y];
                        b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                        b[track[i-1].X][track[i-1].Y] = tmp;                                                        
                    }
                    else if(ny == -1){
                        path.push_back(LEFT);
                        tmp = b[track[i].X][track[i].Y];
                        b[track[i].X][track[i].Y] = b[track[i-1].X][track[i-1].Y];
                        b[track[i-1].X][track[i-1].Y] = tmp;                                                        
                    }                                           
                    if(path.size() >= Limit) return;
                    isDone = true;
                    break;
                }                
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
            if(isDone) break;                     
        }        
    }    
}

void bfs(){
    bool isDone = false;
    vector<pair<int, int>> track;

    for (int i = 0; i < position.size(); i++)
    {
        int x = position[i].X;
        int y = position[i].Y;
        if(b[x][y] == p[x-1][y-1]){
            fix[x][y] = true;
            continue;
        }
        
        track.clear();        
        isDone = false;
        queue<pair<int, int>> q;
        memset(dist, -1, sizeof(dist));
        dist[x][y] = 0;    
        q.push({x, y});        
        while (!q.empty())
        {            
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx <0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(dist[nx][ny] != -1 || fix[nx][ny]) continue;
                prevPath[nx][ny] = {cur.X, cur.Y};
                if(b[nx][ny] == p[x-1][y-1]){
                    while (!(nx == x && ny == y))
                    {
                        track.push_back({nx, ny});
                        int tx = prevPath[nx][ny].X;
                        int ty = prevPath[nx][ny].Y;
                        nx = tx;
                        ny = ty;
                    }                                    
                    track.push_back({x, y});                    
                    moveZero(track);
                    if(path.size() >= Limit) return;
                    isDone = true;
                    fix[x][y] = true;
                    break;
                }                
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }    
            if(isDone) break;        
        }        
    }    
}

void solve(int board[5][5], int pattern[3][3], int callCntLimit) {
    position.push_back({2, 2});
    for (int i =0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            p[i][j] = pattern[i][j];
            if(i ==1 && j == 1) continue;
            position.push_back({i+1, j+1});            
        }        
    }
    Limit = callCntLimit;
    
    do
    {
        path.clear();
        copyBoard(board);
        memset(dist, -1, sizeof(dist));
        memset(fix, false, sizeof(fix));        
        bfs();
        
        if(path.size() < Limit && match()) break;
        
    } while (next_permutation(position.begin()+1, position.begin()+8));
    
    for (int i = 0; i < path.size(); i++)
    {        
        swap(path[i]);
    }
  
}