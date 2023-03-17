def rounded(n):
    temp = n % 10
    if temp >= 5:
        return n + (10-temp)
    return n - temp


def cents(n,d,items,r=None):
    while True:
        currentMin = float('inf')
        if r is None:
            r = [0]*(n+1)
       
        if n == 0:    #no items
            return 0
        
        if d == 0 or n == 0:    # no dividers
            cost = rounded(sum(items))
            if cost < currentMin:
                return cost
        
        else:
            div = 1
            for i in range(1,n):
                r[i] = rounded(sum(items[:i]))+rounded(sum(items[i:]))
                
                if r[i] < currentMin:
                    currentMin = r[i]
                    div = i
            if d > 1:
                if min(cents(div,d-1,(items[:div]),r) + rounded(sum(items[div:])),cents(n-div,d-1,(items[div:]),r) + rounded(sum(items[:div]))) < currentMin:
                    currentMin = min(cents(div,d-1,(items[:div]),r),cents(n-div,d-1,(items[div:]),r))
                    return currentMin
               
            return currentMin
                


if __name__ == '__main__':

     n,d = [int(x) for x in input().split()]
     items = [int(k) for k in input().split()]
     print(cents(n,d,items))
    
