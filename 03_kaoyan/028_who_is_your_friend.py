while True:
    try:
        N, M = map(int, raw_input().strip().split())
        people = [0]*N
        books = [0]*(M+1)
        for i in range(N):
            bookID = input()
            people[i] = bookID
            books[bookID] += 1

        for i in range(N):
            if books[people[i]] == 1:
                print 'BeiJu'
            else:
                print (books[people[i]]-1)
    except:
        break
