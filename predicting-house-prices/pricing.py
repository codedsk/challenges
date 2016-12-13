# https://www.hackerrank.com/challenges/predicting-house-prices

if __name__ == "__main__":

    priced = []
    prices = []
    unpriced = []

    [F,N] = [int(x) for x in raw_input().split()]

    for i in xrange(N):
        r = [float(x) for x in raw_input().split()]
        priced.append(r[0:F])
        prices.append(r[F])

    T = int(raw_input())

    for i in xrange(T):
        r = [float(x) for x in raw_input().split()]
        unpriced.append(r)
