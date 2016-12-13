# Brackets - verify strings have correctly ordered matching opening and closing brackets


values_yes = [
    '',         # empty string test,                       'YES'
    '({[]})',   #                                          'YES'
    '[{}]',     #                                          'YES'
    '()',       #                                          'YES'
    '[[[]]]',   #                                          'YES'
    '{}[]()',   #                                          'YES'
    '[{()()}({[]})]({}[({})])((((((()[])){}))[]{{{({({({{{{{{}}}}}})})})}}}))[][][]'   # 'YES'
]

values_no = [
    '[',        # string length test, no matching bracket  'NO'
    '[}]',      #                                          'NO'
    '[{]',      #                                          'NO'
    '[{]}',     #                                          'NO'
    '[)',       #                                          'NO'
    ')}][{(',   #                                          'NO'
    ')(',       #                                          'NO'
    '][',       #                                          'NO'
    '}{',       #                                          'NO'
    '[[[}]]',   #                                          'NO'
    '{[}]',     #                                          'NO'
    '[{()()}({[]})]({}[({})])((((((()[])){}))[]{{{({({({{{{{{}}}}}})})})}}}))[][][]{', # 'NO'
    '[{()()}({[]})]({}[({})])((((((()[])){}))[]{{{({({({{{{{{}}}}}})})})}}}))[][][]{', # 'NO'
    '[{()()}({[]})]({}[({})])((((((()[])){}))[]{{{({({({{{{{{}}}}}})})})}}}))[][][]]', # 'NO'
    '[{()([)}({[]})]({}[({})])((((((()[])){}))[]{{{({({({{{{{{}}}}}})})})}}}))[][][]'  # 'NO'
]


def test(values):
    results = []
    brackets_close = {
        ']':'[',
        '}':'{',
        ')':'('
    }

    for s in values:
        l = len(s)
        valid = True
        stack = []

        # if length of s is not even, we have mismatched brackets
        if (l%2 != 0):
            results.append('NO')
            continue

        # make one pass through the string,
        # when we see an open bracket character, push it onto the stack.
        # when we see a close bracket character, pop from the top
        # of the stack and check if it is the corresponding open bracket
        # character. if it is, keep moving through the string, if not
        # mark the string as invalid and move to the next string.

        for i in xrange(l):
            c = s[i]
            if c == '{' or c == '[' or c == '(':
                # add open brackets to the stack
                stack.append(c)
            elif c == '}' or c == ']' or c == ')':
                # pop the top of the stack and check if it
                # is the corresponding open bracket
                if len(stack) == 0:
                    valid = False
                    break
                t = stack.pop();
                if brackets_close[c] != t:
                    # close bracket does not match our last open bracket
                    valid = False;
                    break
        # if we reached the end of the string without finding an offense
        # mark the string as valid
        if valid is True:
            results.append('YES')
        else:
            results.append('NO')

    return results

print test(values_yes)
print test(values_no)

