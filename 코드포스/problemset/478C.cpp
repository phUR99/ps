#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
식의 정당성?
개수가 서로 비슷할 경우에는  r+g+b/3의 형태로 가능

*/

int main()
{

    fastio;
    long long r, g, b;
    cin >> r >> g >> b;

    vector<long long> rgb = {r, g, b};
    sort(rgb.begin(), rgb.end(), greater<long long>());

    if (rgb[0] >= 2 * (rgb[1] + rgb[2]))
    {

        cout << rgb[1] + rgb[2] << endl;
    }
    else
    {
        //////
        cout << (r + g + b) / 3 << endl;
    }

    return 0;
}
