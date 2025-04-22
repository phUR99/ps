import sys
t = int(sys.stdin.readline().strip())

while t:
    a, b = map(int, sys.stdin.readline().strip().split())
    sys.stdout.write(f"{a + b}\n")    
    t -= 1