n = int(input())
a_n = [int(i) for i in input().split()]


def little_search(x, a_n):
    l = -1
    r = len(a_n)
    while l + 1 < r:
        m = (l + r) // 2
        if a_n[m] < x:
            l = m
        else:
            r = m
    if l != -1 and a_n[l] == x:
        return l
    else:
        return r


def big_search(x, a_n):
    l = -1
    r = len(a_n)
    while l + 1 < r:
        m = (l + r) // 2
        if a_n[m] <= x:
            l = m
        else:
            r = m
    if r != len(a_n) and a_n[r] == x:
        return r
    else:
        return l


def merge(arr_1, arr_2) -> list:
    if not arr_1:
        return arr_2
    elif not arr_2:
        return arr_1
    c = [0] * (len(arr_1) + len(arr_2))
    i, j = 0, 0
    while i < len(arr_1) or j < len(arr_2):
        if i == len(arr_1):
            c[i + j] = arr_2[j]
            j += 1
        elif j == len(arr_2):
            c[i + j] = arr_1[i]
            i += 1
        elif arr_1[i] < arr_2[j]:
            c[i + j] = arr_1[i]
            i += 1
        else:
            c[i + j] = arr_2[j]
            j += 1
    return c


def merge_sort(lst):
    if len(lst) < 2:
        return lst
    k = len(lst) // 2
    return merge(merge_sort(lst[:k]), merge_sort(lst[k:]))


a_n = merge_sort(a_n)
k = int(input())
for i in range(k):
    x, y = map(int, input().split())
    x_n = little_search(x, a_n)
    y_n = big_search(y, a_n)
    print(y_n - x_n + 1, end=' ')
