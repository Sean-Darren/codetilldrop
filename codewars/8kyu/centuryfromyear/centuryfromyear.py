from math import ceil as c
def century(year):
    # Finish this :
    if year >= 100:
        return c(year/100)
    else: 
        return 1