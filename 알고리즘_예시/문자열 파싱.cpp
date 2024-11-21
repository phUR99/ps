#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 입력이 몇개가 들어온다고 정해지지 않을 때
    /*
    getline(cin, str)의 형식으로 받아줘야 하는데
    첫 입력에서의 개행문자의 문제로 인해서 첫 버퍼가 그냥 지워지는 문제가 발생함 (N-1개 입력만 받는 이유)
    따라서 입력을 받기 전에 cin.ignore()로 버퍼를 지워야함
    */
    string s;
    cin.ignore();
    while (getline(cin, s))
    {
        /* code */
    }

    // 방법 1 find와 substr를 활용
    // 공백 기준으로 문자열을 파싱하기 때문에
    // 맨 마지막 문자열에 공백을 추가해야함
    string str = "GOOD morning";
    str += " ";
    int pos;
    int cur = 0;
    vector<string> arr;
    while ((pos = str.find(' ', cur)) != string::npos)
    {
        int len = pos - cur;
        string temp = str.substr(cur, len);
        arr.push_back(temp);
        cur = pos + 1;
    }
    for (auto &i : arr)
    {
        cout << i << '\n';
    }
    // 방법 2 sstream 헤더의 stringstream 활용하기
    // 문자열을 받아서 원하는 자료형을 추출할 때 사용가능
    int num;
    string strr = "10 20 30 40 50";
    stringstream stream;
    stream.str(strr);
    while (stream >> num)
    {
        cout << num << ' ';
    }
    cout << '\n';
    stream.clear();

    string str3 = "Enter,id1234,Muzi";
    // istringstream ss변수에 string 변수 as로 초기화한다.(ss는 str의 문자열을 가진다.)
    istringstream ss(str3);
    string buff;
    while (getline(ss, buff, ',')) // ss에서 ','(쉽표)까지 입력으로 받아들인다.
    {
        // getline으로 읽어들인 값을 buff에 저장해 출력한다.
        cout << buff << ' ';
    }
    ss.clear();

    return 0;
}