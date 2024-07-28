#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int N, M;
pair<pair<int, int>, double> event[100005];
int coordX[100005], coordY[100005];
double pSumX[100005], pSumY[100005];
double probSumX[100005], probSumY[100005];
pair<int, int> police;

bool cmpX(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
    return a.first.first < b.first.first;
}
bool cmpY(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
    return a.first.second < b.first.second;
}

int main(int argc, char** argv)
{
	int T, test_case;
    fastio;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> event[i].first.first >> event[i].first.second;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> event[i].second;              
        }
        sort(event, event+N, cmpX);
        pSumX[0] = event[0].first.first * event[0].second;
        probSumX[0] = event[0].second;
        coordX[0] = event[0].first.first;
        for (int i = 1; i < N; i++)
        {
            pSumX[i] = pSumX[i-1] + event[i].first.first * event[i].second;
            probSumX[i] = probSumX[i-1] + event[i].second;
            coordX[i] = event[i].first.first;        
        }
        sort(event, event+N, cmpY);
        pSumY[0] = event[0].first.second * event[0].second;
        probSumY[0] = event[0].second;
        coordY[0] = event[0].first.second;
        for (int i = 1; i < N; i++)
        {
            pSumY[i] = pSumY[i-1] + event[i].first.second * event[i].second;
            probSumY[i] = probSumY[i-1] + event[i].second;
            coordY[i] = event[i].first.second;                    
        }
        cin >> M;
        cout << "Case #" << test_case+1 << '\n';        
        double answer;
        cout << fixed;
        cout.precision(6);
        for (int i = 0; i < M; i++)
        {
            answer = 0;            
            cin >> police.first >> police.second;
            int idxX = upper_bound(coordX, coordX + N, police.first) - coordX;
            if(idxX == 0){
                answer += pSumX[N - 1] - police.first * probSumX[N - 1];
            }
            else{
                answer += pSumX[N - 1] - pSumX[idxX - 1] - police.first * (probSumX[N - 1] - probSumX[idxX - 1]);
                answer += police.first * probSumX[idxX - 1] - pSumX[idxX - 1];
            }
            int idxY = upper_bound(coordY, coordY + N, police.second) - coordY;
            if(idxY == 0){
                answer += pSumY[N - 1] - police.second * probSumY[N - 1];
            }
            else{
                answer += pSumY[N - 1] - pSumY[idxY - 1] - police.second * (probSumY[N - 1] - probSumY[idxY - 1]);
                answer += police.second * probSumY[idxY - 1] - pSumY[idxY - 1];
            }
            cout << answer << '\n';
        }
                						
	}

	return 0;
}