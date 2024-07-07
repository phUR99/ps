#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int Answer;
int A[100005], B[100005];
int N, L;

int main(int argc, char** argv)
{
	int T, test_case;    
    fastio;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = -1;
        cin >> N >> L;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }     
        sort(A, A+N); sort(B, B+N);

                          
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}