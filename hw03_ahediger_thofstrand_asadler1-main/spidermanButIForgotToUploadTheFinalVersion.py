def spiderman(M, distances):
    tot = sum(distances)
    if (tot % 2 != 0):
        return "IMPOSSIBLE"
    if (M ==1):
        return "IMPOSSIBLE"
    if (M == 0):
        return ""
    nextNums = 0
    count = 1
    for j in range(M-1):
        if (distances[0] == nextNums + distances[j+1]):
            return("U" + count * "D" + spiderman(M-(j+2), distances[j+2:M]))
        elif (distances[0] < nextNums + distances[j+1]):
            distances[1] += distances[0]
            upMore = "U" + spiderman(M-1, distances[1:M])

            distances[1] -= 2*distances[0]
            downMore = "D" + spiderman(M-1, distances[1:M])
            if(downMore.find("IMPOSSIBLE") != -1):
                return upMore
            if(downMore.find("IMPOSSIBLE") != -1):
                return downMore


        nextNums += distances[j+1]
        count += 1
    return "IMPOSSIBLE"


if name == 'main':
    N = int(input())
    for i in range(N):
        M = int(input())
        distances = [int(k) for k in input().split()]
        out = spiderman(M, distances)
        if(out != "IMPOSSIBLE" and out.find("IMPOSSIBLE") != -1):
            print("IMPOSSIBLE")
            break
        print(out)
