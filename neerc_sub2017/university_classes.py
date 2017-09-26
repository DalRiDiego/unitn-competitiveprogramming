n = int(input())
C = 7
d = [0] * C 
for i in range(n):
    schedule = list(input())
    for c in range(C):
        d[c] += int(schedule[c])
print(max(d))
