def countCost(dist):
    if dist <= L1:
        return C1
    elif dist <= L2:
        return C2
    else:
        return C3

while True:
    try:
        L1, L2, L3, C1, C2, C3 = map(int, raw_input().strip().split())
        A, B = map(int, raw_input().strip().split())
        if A>B:
            A, B = B, A
        N = input()
        dists = [0]*N
        for i in range(1, N):
            dists[i] = input()
        costs = [float('inf')]*N
        costs[A-1] = 0
        for i in range(A, B):
            j = i-1
            while j>=(A-1) and ((dists[i]-dists[j])<=L3):
                costs[i] = min(costs[i], costs[j]+countCost(dists[i]-dists[j]))
                j -= 1
        print costs[B-1]
    except:
        break
