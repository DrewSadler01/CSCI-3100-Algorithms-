def favEnding(pages, pgNum, r=None):
    if (r is None):
        r=[float('-inf')]*401

    if(r[int(pgNum)] != float('-inf')):
        return r[int(pgNum)]

    if(pages[int(pgNum)][0] == "favourably"):
        r[int(pgNum)] = 1
        return 1

    if(pages[int(pgNum)][0] == "catastrophically"):
        r[int(pgNum)] = 0
        return 0

    r[int(pgNum)] = favEnding(pages, pages[int(pgNum)][0], r) + favEnding(pages, pages[int(pgNum)][1], r) + favEnding(pages, pages[int(pgNum)][2], r)
    return r[int(pgNum)]



if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = int(input())
        pages = {}
        for j in range(S):
            val = input()
            splitVal = val.split()
            pages[int(splitVal[0])] = splitVal[1:]
        print(favEnding(pages, 1))
