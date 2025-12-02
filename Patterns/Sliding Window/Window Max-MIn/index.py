from collections import deque

def sliding_window(nums, k):
    n = len(nums)

    min_dq = deque()
    max_dq = deque()

    min_window = []
    max_window = []

    for i in range(n):
        if min_dq and min_dq[0] <= i - k:
            min_dq.popleft()

        if max_dq and max_dq[0] <= i - k:
            max_dq.popleft()

        while min_dq and nums[min_dq[-1]] > nums[i]:
            min_dq.pop()

        while max_dq and nums[max_dq[-1]] < nums[i]:
            max_dq.pop()


        min_dq.append(i)
        max_dq.append(i)

        if(i >= k - 1):
            min_window.append(nums[min_dq[0]])
            max_window.append(nums[max_dq[0]])

    return min_window, max_window

nums = [1, 3, 2, 6, -1, 4, 1, 8, 2]
k = 3

min_window, max_window = sliding_window(nums, k)

print(min_window)
print(max_window)