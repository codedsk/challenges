def bubblesort(a):
    l = len(a)
    swaps = 1
    while swaps > 0:
        swaps = 0
        for i,j in zip(range(0,l-1),range(1,l)):
            if a[i] > a[j]:
                t = a[i]
                a[i] = a[j]
                a[j] = t
                swaps += 1
    return a
