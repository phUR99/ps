
#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int Answer;
int A, B;

int main(int argc, char** argv)
{
    fastio;
	int T, test_case, N;
    string str;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        
        cin >> N;
        cin >> str;
        A = 0; B = 0;
        int st = 0;
        for (int ed = 0; ed < N; ed++)
        {
            if(str[ed] == 'A') A++;
            else B++;
            if(str[ed] == 'A' && ed - st >= 1){
                int tmp = max(0, A - B);
                Answer += tmp;
                while (st != ed)
                {
                    if(str[st] == 'A') A--;
                    else B--;
                    st++;
                }                
            }
        }
        
            		
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}