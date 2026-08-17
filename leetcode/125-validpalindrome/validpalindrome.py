class Solution:
    def isPalindrome(self, s: str) -> bool:
        temp = ""

        for c in s:
            if c.isalnum():
                temp += c.lower()

        idx = 0
        last = len(temp) -1

        while(idx < last):
            if(temp[idx] != temp[last]):
                return False
            idx += 1
            last -= 1


        return True