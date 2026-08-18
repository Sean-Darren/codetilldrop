class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        opener = ['(', '{', '[']

        for i in s:
            if i in opener:
                stack.append(i)
            else:

                if not stack:
                    return False
                
                current = stack.pop()

                if(i == ')' and current != "("):
                    return False
                elif(i == '}' and current != "{"):
                    return False
                elif(i == ']' and current != "["):
                    return False
        
        return len(stack) == 0
                