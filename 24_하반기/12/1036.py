import sys
import itertools

def solve():
    n = int(input())  # 문자열의 개수
    count = dict()  # 문자의 가중치를 기록할 딕셔너리
    for i in list("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"):
        count[i] = 0  # 가능한 모든 문자에 대해 초기화
    n_list = list()
    for _ in range(n):
        n_list.append(sys.stdin.readline().strip())  # n개의 문자열 입력받기
        
    k = int(input())  # 가중치 기준으로 바꿀 문자들의 개수
    
    for i in n_list:
        for j in range(len(i)):
            count[i[::-1][j]] += 36 ** j  # 문자열을 뒤집고, 각 문자의 가중치를 계산하여 count에 더함
    
    for i in count.keys():
        count[i] = count[i] * (35 - int(i, 36))  # 각 문자의 가중치를 35 - 해당 문자의 숫자 값으로 곱함
    count = sorted(count.items())  # 튜플 리스트로 변환 후 정렬
    count.sort(key=lambda x: -x[1])  # 가중치 내림차순 정렬
    
    for i in count[:k]:
        for j in range(len(n_list)):
            n_list[j] = n_list[j].replace(i[0], "Z")  # 가장 중요한 k개의 문자를 "Z"로 변경
    
    s = 0
    for i in n_list:
        s += int(i, 36)  # 문자열을 36진법으로 변환하여 합산
    
    print(to_36(s))  # 합산된 값을 다시 36진법으로 출력
    
def to_36(n):
    d = list("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    a, b = n // 36, n % 36  # 나누기와 나머지 연산으로 36진법 변환
    w = d[b]  # 나머지 값을 대응하는 문자로 변환
    return to_36(a) + w if a != 0 else w  # 재귀적으로 36진법 문자열을 만들며 반환

solve()
