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
            return("U" + spiderman(M-1, distances[1:M]))
        nextNums += distances[j+1]
        count += 1


if __name__ == '__main__':
    N = int(input())
    for i in range(N):
        M = int(input())
        distances = [int(k) for k in input().split()]
        out = spiderman(M, distances)
        if(out != "IMPOSSIBLE" and out.find("IMPOSSIBLE") != -1):
            print("IMPOSSIBLE")
            break
        print(out)
