class Solution:
    def isValid(self, s: str) -> bool:
        map = {'(':')',
        '{':'}',
        '[':']',
        }

        if len(s)%2 != 0:
            return False
 
        stack = []

        for bracket in s:
            if bracket in map:
                stack.append(bracket)

            else:
                if len(stack)==0 or map[stack.pop()] != bracket :
                    return False
        # print(stack)
        if stack:
            return False
        
        else:
            return True
