# https://www.hackerrank.com/challenges/grid-challenge

def bubblesort(a):
    """Bubble Sort algorithm for sorting a sequence container of values.
    """
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

def is_second_dimension_sorted(rows):
    """Check if a 2 dimensional square sequence is sorted
       in the 2nd (column) dimension
    """
    columns = zip(*rows)
    l = len(columns)
    for c in columns:
        for i,j in zip(range(0,l-1),range(1,l)):
            if c[i] > c[j]:
                return False
    return True


def is_sortable(rows):
    """check if a two dimensional grid is sortable by sorting the first dimension
       using an adjacent element swapping algorithm and checking if the second
       dimension ends up being sorted as well.
    """
    sorted_rows = []
    for row in rows:
        # it doesnt matter how we sort the row to tell
        # if the matrix is sortable, but we use bubble
        # sort anyway to keep the spirit of the problem.
        sorted_rows.append(bubblesort(row))

    # check columns are sorted
    return is_second_dimension_sorted(rows)


def get_testcase():
    # read the number of rows/cols in the test case
    N = int(raw_input().strip())

    for i in range(N):
        row = list(raw_input().strip())

        # row must only contain english letters
        for i in range(len(row)):
            if row[i] < 'a' or row[i] > 'z':
                raise Error("Invalid input: ",row[i])

        rows.append(row)

    return rows


if __name__ == "__main__" :

    # read the number of test cases
    T = int(raw_input().strip())
    testcases = []
    rows = []

    for test in range(T):

        rows = get_testcase()
        testcases.append(rows)

    for test in testcases:
        sortable = is_sortable(test)
        print sortable
