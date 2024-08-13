#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int Answer;
map<int, int> tree[400005];
int arr[400005];


int main(int argc, char** argv)
{
	int T, test_case, N;
    fastio;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
        int S = 1;
        while (S < N)
        {
            S *= 2;
        }
        
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            
        }
        

        for (int i = 0; i < N; i++)
        {
            tree[S+i].insert({arr[i], 1});
        }
        for (int i = S - 1; i > 0; i--)
        {
            if(tree[i].find(arr[i*2]) == tree[i].end()){
                tree[i].insert({arr[i*2], 1});
            }
            else{
                tree[i][i*2]++;
            }
            if(tree[i].find(arr[i*2+1]) == tree[i].end()){
                tree[i].insert({arr[i*2+1], 1});
            }
            else{
                tree[i][i*2+1]++;
            }
        }
        

		Answer = 0;        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
        for (int i = 0; i <= S; i++)
        {
            tree[i].clear();
        }         
	}

	return 0;
}