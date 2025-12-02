def window_sum_size_k(lst, k):
    ans = []

    window_sum = 0
    for i in range(0, k):
        window_sum += lst[i]

    ans.append(window_sum)

    for i in range(k, len(lst)):
        window_sum += lst[i] - lst[i - k]
        ans.append(window_sum)

    print(ans)

k = 3
list = [1, 3, 2, 6, -1, 4, 1, 8, 2]
window_sum_size_k(list, 3)

