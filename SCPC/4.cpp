#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int Answer;
int N;
vector<int> maxIdx, minIdx;
int arr[50050];

int main(int argc, char** argv)
{
	int T, test_case;
    fastio;

	cin >> T;
    
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
		Answer = 0;
        maxIdx.clear(); minIdx.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int M = *max_element(arr, arr+N);
        int m = *max_element(arr, arr+N);
        for (int i = 0; i < N; i++)
        {
            if(arr[i] == m) minIdx.push_back(i);
            if(arr[i] == M) maxIdx.push_back(i);
        }
        cout << "Case #" << test_case+1 << '\n';
        if(minIdx.size() + maxIdx.size() == N  && (minIdx.size()  == N / 2 || maxIdx.size() == N / 2)){
            cout << Answer << '\n';
        }
        else{
            for (int i = 0; i < minIdx.size(); i++)
            {
                int high = upper_bound(maxIdx.begin(), maxIdx.end(), minIdx[i]) - maxIdx.begin();
                int low = lower_bound(maxIdx.begin(), maxIdx.end(), minIdx[i]) - maxIdx.begin();
                cout << high << low << '\n';
            }
            for (int i = 0; i < maxIdx.size(); i++)
            {
                
            }
            


            cout << Answer << '\n';
            
        }
		
		
	}

	return 0;
}