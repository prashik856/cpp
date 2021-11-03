'''
Fizzbuzz is one of the most basic problems in the coding interview world. Try to write a small and elegant code for this problem.

Given a positive integer A, return an array of strings with all the integers from 1 to N. 

But for multiples of 3 the array should have “Fizz” instead of the number. 

For the multiples of 5, the array should have “Buzz” instead of the number. 

For numbers which are multiple of 3 and 5 both, the array should have “FizzBuzz” instead of the number.

Look at the example for more details.

Example

A = 5
Return: [1 2 Fizz 4 Buzz]
'''

'''
Easy enough!
'''
import random

def fizzBuzz(a):
    result = []
    for i in range(1, a+1):
        if(i % 3 == 0 and i % 5 == 0):
            result.append("FizzBuzz")
        elif(i % 3 == 0):
            result.append("Fizz")
        elif(i % 5 == 0):
            result.append("Buzz")
        else:
            result.append(str(i))
    return result

limit = 100
a = random.randint(0, limit)
a = 5
print("Given input is: " + str(a))
result = fizzBuzz(a)
print(result)