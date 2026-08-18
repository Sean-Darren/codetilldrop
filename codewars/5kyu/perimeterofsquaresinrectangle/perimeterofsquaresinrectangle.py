def perimeter(n):
    a = [1,1]
    b = (n+1)-2
    for i in range(b):
        jumlah = a[-1] + a[-2]
        a.append(jumlah)
    return 4* sum(a)