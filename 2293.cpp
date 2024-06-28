#include <bits/stdc++.h>

using namespace std;
#define ll long long
int d[10001];
int arr[10001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	d[0] = 1;
	for (int i = 0; i <n; i++)
	{
		for (int j = arr[i]; j <= k; j++) {
			d[j] += d[j - arr[i]];
		}
	}
	cout << d[k];
}
