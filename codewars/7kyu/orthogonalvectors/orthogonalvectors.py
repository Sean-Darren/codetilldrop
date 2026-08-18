def is_orthogonal(u, v): 
    # your code here
    sum = 0
    for i in range(len(u)):
        product = u[i] * v[i]
        sum += product
    if sum == 0:
        return True
    else: return False