def filter_string(st):
    isi = ''
    for i in st:
        if i.isdigit():
            isi += str(i)
        else: continue
    return int(isi)