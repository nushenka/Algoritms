n = int(input())
a = list(map(int, input().split()))
k = int(input())
size_block = int(len(a) ** (1 / 2)) + 1
inf = 10 ** 6
block = [-inf] * (len(a) // size_block + 1)
index = [0] * (len(a) // size_block + 1)
for i in range(len(a)):
    if block[i // size_block] < a[i]:
        index[i // size_block] = i
    block[i // size_block] = max(block[i // size_block], a[i])


def max_arr(left, right):
    ans = -inf
    while left <= right:
        if left // size_block != right // size_block and left % size_block == 0:
            if block[left // size_block] > ans:
                ans = block[left // size_block]
                res = index[left // size_block]
            left += size_block
        else:
            if a[left] > ans:
                ans = a[left]
                res = left
            left += 1

    return res + 1


r = []
for i in range(k):
    left, right = map(int, input().split())
    r.append(max_arr(left - 1, right - 1))
print(*r)