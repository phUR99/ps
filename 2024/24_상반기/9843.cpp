#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ull unsigned long long
using namespace std;


int main(int argc, char** argv)
{
    fastio;
    int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
    ull N, low, high, mid;
    int ans;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        low = 0;
        high = 10'000'000'000;
        ans = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if(mid * (mid + 1)/2 > N) high = mid - 1;                            
            else{
                if(mid * (mid + 1)/2 == N) ans = mid;
                low = mid + 1;
            }   
        }        
        cout << "#" << test_case << ' ';
        cout << ans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}