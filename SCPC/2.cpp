#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

long long Answer;

int N, Q;
vector<pair<long long, int>> W;

bool comp(pair<long long, int> &a, pair<long long, int> &b){
    return a.second < b.second;
}

int main(int argc, char** argv)
{
    fastio;
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        W.clear();        
		Answer = 0;
        cin >> N >> Q;
        long long weight, q;
        for (int i = 0; i < N; i++)
        {
            cin >> weight;
            W.push_back({weight, i + 1});            
        }                
        int n;
        cout << "Case #" << test_case+1 << '\n';            
        for (int i = 0; i < Q; i++)
        {
            sort(W.begin(), W.end());   
            cin >> q;            
            n = N;
            q--;
            long long pre = 0;
            for (int j = 0; j < N; j++, n--)
            {                
                long long s = (long long) (W[j].first - pre) * n;
                if(s == 0) continue;
                if(s <= q){
                    q -= s;
                    pre = W[j].first;
                }
                else{
                    q %= n;
                    sort(W.begin()+j, W.end(), comp);                                        
                    Answer += W[j + q].second;                    
                    break;
                }
            }                                                                                      
        }   
        cout << Answer << '\n';         				
	}        
    
    return 0;
}