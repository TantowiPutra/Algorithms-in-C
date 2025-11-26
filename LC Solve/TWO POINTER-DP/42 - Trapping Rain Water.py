class Solution:
    def trap(self, height) -> int:
        left, right       = 0, len(height) - 1
        leftMax, rightMax = height[left], height[-1]
        water             = 0

        while right > left:
            # print(left, right, leftMax, rightMax) 

            if height[left] <= height[right]:
                leftMax = max(leftMax, height[left])
                water  += max(leftMax - height[left], 0)
                left += 1
            else: 
                # height[right] < height[left]
                rightMax = max(rightMax, height[right])
                water   += max(rightMax - height[right], 0)
                right -= 1

        return water
        
    def trap_dp(self, height) -> int:
        # PREFIX / SUFFIX MAX
        suffixMax  = [0 for x in height]
        postfixMax = [0 for x in height]

        suffixMax[0]  = height[0]
        for x in range(1, len(height)):
            suffixMax[x] = max(suffixMax[x - 1], height[x])

        postfixMax[-1] = height[len(height) - 1]
        for x in range(len(height) - 2, -1, -1):
            postfixMax[x] = max(postfixMax[x + 1], height[x])

        water = 0
        for x in range(0, len(suffixMax)):
            water += min(suffixMax[x], postfixMax[x]) - height[x]

        return water
    
list = [0,1,0,2,1,0,1,3,2,1,2,1]
new_solution = Solution()

print(new_solution.trap(list))
print(new_solution.trap_dp(list))
