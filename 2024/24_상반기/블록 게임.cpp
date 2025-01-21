#include <string>
#include <vector>
#include <cstring>

using namespace std;

int boardArr[52][52];
int answer = 0;
int block[][3][3] ={
    {
        {1, 0, 0},
        {1, 1, 1},
        {0, 0 ,0},
    },
    {
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 0},
    },
    {
        {0, 0, 1},
        {1, 1, 1},
        {0, 0 ,0},
    },
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 1, 0},
    },
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0},
    }
};
void eraseblock(int x, int y, int b){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(!block[b][i][j]) continue;
            boardArr[x+i][y+j] = 0;
        }        
    }
}

void checkblock(int x, int y, int b){
    vector<int> sameblock;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int cur = boardArr[x+i][y+j];
            if(!block[b][i][j]) continue;
            if(cur == -1) return;
            if(cur != 0){
                if(sameblock.empty()) sameblock.push_back(cur);
                else {
                    if(sameblock.back() != cur) return;        
                    sameblock.push_back(cur);            
                }
            }
        }        
    }
    if(sameblock.size() < 4) return;

    if (b == 0){
        int y1 = y +1;
        int y2 = y +2;
        int x1 = x;
        int x2 = x;
        while (x1 >= 0 && boardArr[x1][y1] == 0) x1--;
        while (x2 >= 0 && boardArr[x2][y2] == 0) x2--;
        if(!(x1 == -1 && x2 == -1)) return;        
    }
    else if(b == 1){
        int y1 = y;
        int x1 = x + 1;
        while (x1 >= 0 && boardArr[x1][y1] == 0) x1--;
        if(x1 != -1) return;                
    }
    else if(b == 2){
        int y1 = y;
        int y2 = y+1;
        int x1 = x;
        int x2 = x;
        while (x1 >= 0 && boardArr[x1][y1] == 0) x1--;
        while (x2 >= 0 && boardArr[x2][y2] == 0) x2--;
        if(!(x1 == -1 && x2 == -1)) return;        
    }
    else if(b == 3){
        int y1 = y + 1;
        int x1 = x + 1;
        while (x1 >= 0 && boardArr[x1][y1] == 0) x1--;
        if(x1 != -1) return;                
    }
    else {
        int y1 = y;
        int y2 = y+2;
        int x1 = x;
        int x2 = x;
        while (x1 >= 0 && boardArr[x1][y1] == 0) x1--;
        while (x2 >= 0 && boardArr[x2][y2] == 0) x2--;
        if(!(x1 == -1 && x2 == -1)) return;     
    }
    answer++;
    eraseblock(x, y, b);
}


int solution(vector<vector<int>> board) {

    memset(boardArr, -1, sizeof(boardArr));

    int N = board.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            boardArr[i][j] = board[i][j];
        }
        
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int b = 0; b < 5; b++)
            {
                checkblock(i, j, b);
            }
            
        }
        for (int j = N-1; j >= 0; j--)
        {
            for (int b = 0; b < 5; b++)
            {
                checkblock(i, j, b);
            }
            
        }
        
    }
    
    return answer;
}