import sys

input = sys.stdin.readline

m, n = map(int, input().split())

# 정답 배열 (m x m 크기, 초기값 1)
array = [[1] * m for _ in range(m)]

# 성장 누적 배열 (2m-1 크기)
grow = [0] * (2 * m - 1)

# 입력 처리 및 grow 누적
for _ in range(n):
    a, b, c = map(int, input().split())  # 0, 1, 2의 개수
    for i in range(a, a + b):
        grow[i] += 1
    for i in range(a + b, 2 * m - 1):
        grow[i] += 2

# grow를 array에 반영 (왼쪽 열: 아래에서 위로)
idx = 0
for i in range(m - 1, -1, -1):
    array[i][0] += grow[idx]
    idx += 1

# grow를 array에 반영 (윗줄: 왼쪽에서 오른쪽)
for j in range(1, m):
    array[0][j] += grow[idx]
    idx += 1

# 나머지 영역은 위에서 그대로 복사
for i in range(1, m):
    for j in range(1, m):
        array[i][j] = array[i - 1][j]

# 출력 (슬라이싱/언팩/슬로우 I/O 없음)
for row in array:
    sys.stdout.write(" ".join(map(str, row)) + "\n")
