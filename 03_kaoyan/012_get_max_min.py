while True:
    try:
        N = input()
        num = map(int, raw_input().strip().split())
        print max(num), min(num)
    except:
        break
