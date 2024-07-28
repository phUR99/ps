#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long Answer;
int N, S, E;
int arr[300005];
long long cache[300005][2][2];
const long long INF = 1LL<<63 -1;
long long weight[2];
vector<pair<int, long long>> weightArr;

int main(int argc, char** argv)
{
    fastio;
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;        
        weightArr.clear();
        cin >> N >> weight[0] >> weight[1];        
        
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int cur = arr[0];
        long long cnt = 1;
        for (int i = 1; i < N; i++)
        {
            if(cur == arr[i]) cnt++;
            else {
                weightArr.push_back({cur, cnt * weight[cur]});
                cur = arr[i];
                cnt = 1;
            }
        }
        weightArr.push_back({cur, cnt * weight[cur]});        
        int size = weightArr.size();
        for (int i = 0; i <= size; i++)
        {
            cache[i][0][0] = INF; cache[i][1][1] = INF; cache[i][1][0] = INF; cache[i][0][1] = INF;
        }                        
        cache[0][0][0] = 0; cache[0][1][1] = 0;
        for (int i = 1; i <= size; i++)
        {
            if(weightArr[i-1].first == 0){
                cache[i][0][0] = cache[i-1][0][0];
                cache[i][0][1] = min(cache[i-1][1][1], cache[i-1][0][1]);                
                cache[i][1][1] = min(cache[i-1][1][1], cache[i-1][0][0]) + weightArr[i-1].second;                
            }
            else{
                cache[i][1][1] = min(cache[i-1][1][1], cache[i-1][0][0]);
                cache[i][0][1] = min(cache[i-1][1][1], cache[i-1][0][1]) + weightArr[i-1].second;               
                cache[i][0][0] = cache[i-1][0][0] + weightArr[i-1].second;
            }
        }
        Answer = min({cache[size][0][0], cache[size][0][1], cache[size][1][1]});


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}