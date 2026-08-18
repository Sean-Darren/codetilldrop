class Solution:
    def trap(self, height: List[int]) -> int:
        leftwall = 0
        rightwall = 0

        length = len(height)

        maxleft = [0] * length
        maxright = [0] * length

        for i in range(length):
            maxleft[i] = leftwall

            leftwall = max(leftwall, height[i])

        for i in range(length-1,-1, -1):
            maxright[i] = rightwall

            rightwall = max(rightwall, height[i])  

        sums = 0
        for j in range(length):
            pot = min(maxleft[j], maxright[j])

            sums += max(0, pot - height[j])

        return sums

