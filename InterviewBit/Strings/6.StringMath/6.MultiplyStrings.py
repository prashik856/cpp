'''
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.

For example, 

given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 

We will retroactively disqualify such submissions and the submissions will incur penalties.
'''
'''
Man, I should just solve string math problems in python itself, to avoid these stupid scenarios
'''

def solve(a, b):
    aint = int(a)
    bint = int(b)
    intResult = aint * bint
    result = str(intResult)
    return result

a = "12123324234324324979827394832082034234329792394328648234298720970932786876876872683479234982738462397492342"
b = "2312323213233252353249798268763842987927987823698432986853265279279872983740983268327952735027093275209835709253"

result = solve(a, b)
print("Result is: ")
print(result)