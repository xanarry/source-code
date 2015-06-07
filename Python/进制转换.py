def convert(num, base):
    if base == 1:
        return None
    nums = "0123456789ABCDEF"
    dest = ""
    while num > 0:
        dest = nums[num % base] + dest
        num //= base
    return dest

num, base = map(int, input("input decimal number and base separated by space: ").strip().split())
print(convert(num, base))


