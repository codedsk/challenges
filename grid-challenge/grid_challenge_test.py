import grid_challenge as gc

# bubblesort()

def test_bubblesort_1():
    row = ['a', 'b', 'c']

    assert gc.bubblesort(row) == ['a','b','c']


def test_bubblesort_2():
    row = ['a', 'c', 'b']

    assert gc.bubblesort(row) == ['a','b','c']


def test_bubblesort_3():
    row = ['c', 'a', 'b']

    assert gc.bubblesort(row) == ['a','b','c']


# is_second_dimension_sorted()

def test_2dimsorted_1():
    rows = [['c', 'a'],
            ['b', 'a']]

    assert gc.is_second_dimension_sorted(rows) == False


def test_2dimsorted_2():
    rows = [['c', 'a'],
            ['c', 'a']]

    assert gc.is_second_dimension_sorted(rows) == True


def test_2dimsorted_3():
    rows = [['c', 'a'],
            ['v', 'a']]

    assert gc.is_second_dimension_sorted(rows) == True


# is_sortable()

def test_sortable_1():
    rows = [['a', 'b', 'c'],
            ['a', 'f', 'j'],
            ['a', 'm', 'z']]

    assert gc.is_sortable(rows) == True

def test_sortable_2():
    rows = [['a', 'b', 'c'],
            ['a', 'f', 'j'],
            ['a', 'b', 'z']]

    assert gc.is_sortable(rows) == False

def test_sortable_3():
    rows = [['e', 'b', 'a', 'c', 'd' ],
            ['f', 'g', 'h', 'i', 'j' ],
            ['o', 'l', 'm', 'k', 'n' ],
            ['t', 'r', 'p', 'q', 's' ],
            ['x', 'y', 'w', 'u', 'v' ]]

    assert gc.is_sortable(rows) == True

