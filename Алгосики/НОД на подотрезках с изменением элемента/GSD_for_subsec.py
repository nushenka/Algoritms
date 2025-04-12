n = int(input())
a = [1] + list(map(int, input().split()))
size = int(n ** (1 / 2)) + 1
m = int(input())
block = [0] * size
res = []


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


for i in range(n + 1):
    block[i // size] = gcd(block[i // size], a[i])
for i in range(m):
    line = input().split()
    cmd = line[0]
    if cmd == "u":
        index, value = int(line[1]), int(line[2])
        a[index] = value
        st = index // size * size
        en = min(st + size, n)
        a[index] = value
        block[index // size] = 0
        for j in range(st, en):
            block[index // size] = gcd(a[j], block[j // size])
    else:
        left, right = int(line[1]), int(line[2])
        ans = 0
        while left <= right:
            if left // size != right // size and left % size == 0:
                ans = gcd(block[left // size], ans)
                left += size
            else:
                ans = gcd(a[left], ans)
                left += 1
        res.append(ans)
print(*res)
