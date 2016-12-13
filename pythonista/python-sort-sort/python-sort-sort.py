# https://www.hackerrank.com/contests/pythonist/challenges/python-sort-sort

def get_testcase():
    table = []
    [N,M] = [int(x.strip()) for x in raw_input().strip().split()]
    for n in xrange(N):
        table.append([int(x.strip()) for x in raw_input().strip().split()])
    K = int(raw_input().strip())
    return N,M,table,K


if __name__ == "__main__" :

    # read the test case
    N,M,table,K = get_testcase()

    # sort the table based on the index K
    sorted_table = sorted(table,key=lambda row: row[K])

    # print the sorted table
    s = ""
    for row in sorted_table:
        s += " ".join(map(str,row)) + "\n"
    print s.strip()
