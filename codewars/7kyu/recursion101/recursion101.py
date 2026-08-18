def solve(a,b):
    if a == 0 or b == 0:
        return [a,b]
    elif a >= (2*b):
        a = a - (2*b)
        return solve(a,b)
    elif b >= (2*a):
        b = b - (2*a)
        return solve(a,b)
    else:
        return [a,b]