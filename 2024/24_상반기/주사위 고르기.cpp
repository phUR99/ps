#include <string>
#include <vector>
#include <string.h>
//이분탐색을 위한 헤더
#include <algorithm>

using namespace std;
// 주사위의 리스트
vector<vector<int>> order;
// order에 해당되는 주사위의 합
vector<int> sum[300];
int arr[5];
int n;
// 주사위의 리스트를 만드는 함수
void func(int cnt, int cur){
	// 기저조건 : n에 도달했을 경우
	if (cnt == n){
		vector<int> temp;
		for (int i = 0; i < n; i++)
		{
			temp.push_back(arr[i]);
		}
		order.push_back(temp);
		return;
	}
	// 중복되는 경우가 생기면 안되므로 i는 항상 cur보다 크다
	for (int i = cur + 1; i < 2 *n; i++)
	{
		arr[cnt] = i;
		func(cnt+1, i);
	}	
}
// 주사위의 합을 만드는 함수
void make(int order, int cnt, vector<vector<int>> &dice, vector<int> list){
	if (cnt == n){
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp += dice[list[i]][arr[i]];
		}
		sum[order].push_back(temp);
		return;
	}
	// 중복되는 경우를 고려해야 하므로 i는 0부터 시작한다.
	for (int i = 0; i < 6; i++)
	{
		arr[cnt] = i;
		make(order, cnt+1, dice, list);
	}
	

}

vector<int> solution(vector<vector<int>> dice) {
    
	vector<int> answer;


	n = (int)dice.size() / 2;

	int exp = 1;
	// A와 B를 구분해주는 배열
	bool choose[10];
	vector<int> B;
	func(0, -1);


	for (int i = 0; i < n; i++)
	{
		exp *= 6;
	}
	

	for (int i =0; i < order.size(); i++)
	{	
		make(i, 0, dice, order[i]);
		//이분탐색을 위한 정렬
		sort(sum[i].begin(), sum[i].end());
	}

	int max_win = 0;
	int max_ord = 0;

	for (int i =0; i < order.size(); i++)
	{	
		//초기화
		memset(choose, false, sizeof(choose));
		B.clear();
		//A에서 사용하는 주사위를 마킹
		for (auto number : order[i])
		{				
			choose[number] = true;
		}	
		//B에서 사용하는 주사위 리스트 고르기
		for (int j = 0; j < 2 *n; j++)
		{
			if(!choose[j])	B.push_back(j);
		}
		//order 벡터에서 B의 인덱스
		int b_ord = 0;
		//order를 탐색하면서 B와 동일한 인덱스를 찾는다.
		for (int j = 0; j < order.size(); j++)
		{			
			bool flag = false;
			for (int k = 0; k < n; k++)
			{
				int number_1 = order[j][k];
				int number_2 = B[k];
				if(number_1 != number_2) {
					flag = true;
					break;
				}				
			}
			if(flag) continue;
			b_ord = j;
			break;			
		}
		int win = 0;
		for (int j = 0; j < exp; j++)
		{
			int node = sum[i][j];
			//upper_bound는 초과하는 인덱스 반환 -> 무승부로 판정되는 같은 값을 제거하기 위해서 0.1만큼 뺌
			int temp = upper_bound(sum[b_ord].begin(), sum[b_ord].end(), node-0.1) - sum[b_ord].begin();
			win += temp;
		}
		// 최대 승리 개수 갱신시 인덱스 갱신
		if(win > max_win){
			max_win = win;
			max_ord = i;
		}		
		
	}
	for (int i = 0; i < n; i++)
	{
		answer.push_back({order[max_ord][i]+1});
	}
	return answer;
    
}