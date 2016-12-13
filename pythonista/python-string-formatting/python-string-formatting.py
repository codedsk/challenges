# https://www.hackerrank.com/contests/pythonist/challenges/python-string-formatting

if __name__ == "__main__" :

    # read the test case
    N = int(raw_input().strip())

    # get the width of the field based on largest binary repr
    w = len(bin(N))-2

    # dynamically generate a string format
    f = '{:%dd} {:%do} {:%dX} {:%db}' % (w,w,w,w)

    # print out the table of formatted values
    for i in xrange(1,N+1):
        print f.format(i,i,i,i)
