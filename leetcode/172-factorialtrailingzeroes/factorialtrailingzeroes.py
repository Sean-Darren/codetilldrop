class Solution:
    def factorial(n:int) -> int:
        if n == 0 or n == 1:
            return 1
        else:
            return n * factorial(n-1)
    
    def trailingZeroes(self, n: int) -> int:

        factorialanswer = factorial(n)
        count = 0 
        while True:
            n = factorialanswer%10

            factorialanswer = factorialanswer//10

            if(n == 0):
                count +=1
            else:
                break

        return count
        