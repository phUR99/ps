
#include <iostream>
#include <algorithm>

using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long Answer;
int thing[300005];

int main(int argc, char** argv)
{
	int T, test_case, N;
    fastio;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
        Answer = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> thing[i];
        }
        sort(thing, thing+N);
        for (int i = 0; i < N/4; i++)
        {
            Answer += (thing[3*(N/4)+i] - thing[i]) *2;
        }
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}