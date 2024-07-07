#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    vector<long long> arr;
    for (int i =0; i < food_times.size(); i++){
        arr.push_back(food_times[i]);
        
    }
    sort(arr.begin(), arr.end());
    long long M = arr.back();
    long long total = 0;
    for (auto i : arr)
    {
        total += i;
    }
    if(k >= total) return answer;
    long long size = arr.size();
    int prev = 0;
    int tmp = 0;
    //////////
    for(int i = 0; i < size; i++)
    {
        long long t =(long long)(arr[i] - prev) * (size - i);
        if(t == 0) continue;
        if(t <= k){
            k -= t;
            prev = arr[i];
        }
        else{
            tmp = i;
            break;
        }
                
    }         
    ////////////       
    k %= (size - tmp);
    for (int i = 0; i < food_times.size(); i++)
    {
        if(food_times[i] < arr[tmp]) continue;
        if(k == 0){
            answer = i + 1;
            break;
        }
        k--;
    }    
    return answer;
}