class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        maxLength = 0

        seen = set()

        for right in range(len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left += 1
            
            seen.add(s[right])
            maxLength = max(maxLength, right-left + 1)

        return maxLength