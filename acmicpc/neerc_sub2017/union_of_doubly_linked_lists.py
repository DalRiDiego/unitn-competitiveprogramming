n = int(input())
C = [0] * (n+1)
def vis(i, label, L, R):
    if C[i] == 0:
        C[i] = label
        if L[i] != 0:
            vis(L[i], label, L, R)
        if R[i] != 0:
            vis(R[i], label, L, R)

L = [0] * (n+1)
R = [0] * (n+1)
label = 1
for i in range(1, n+1):
    l, r = list(map(int, input().split()))
    L[i] = l
    R[i] = r

for i in range(1, n+1):
    if C[i] == 0:
        vis(i, label, L, R)
        label+=1
label-=1
for i in range(1, n+1):
    if label == 1:
        break

    if L[i] != 0 and R[i] != 0:
        continue
    for j in range(1, n+1):
        if i != j:
            if L[i] == 0 and R[j] == 0 and C[i] != C[j]:
                L[i] = j
                R[j] = i
                target = C[j]
                newL = C[i]
                for k in range(1, n+1):
                    if C[k] == target:
                        C[k] = newL
                label-=1
            elif R[i] == 0 and L[j] == 0 and C[i] != C[j]:
                R[i] = j
                L[j] = i
                target = C[j]
                newL = C[i]
                for k in range(1, n+1):
                    if C[k] == target:
                        C[k] = newL
                label-=1

for i in range(1, n+1):
    print(str(L[i]) + " " + str(R[i]))
