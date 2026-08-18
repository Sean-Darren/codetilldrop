def make_readable(second):
    if second < 60:
        HH = '00'
        MM = '00'
        if second < 10:
            SS = '0' + str(second)
        else:
            SS = str(second)
    if second >= 60 and second<3600:
        HH = '00'
        minutes = second // 60
        if second >= 600: 
            MM = str(minutes)
        else:
            MM = '0' + str(minutes)
        detik = (second % 60)
        if detik < 10:
            SS = '0' + str(detik)
        else:
            SS = str(detik)
    if second >= 3600:
        jam = second // 3600
        if jam < 10:
            HH = '0' + str(jam)
        else:
            HH = str(jam)
        minutes = (second % 3600)
        if minutes < 60:
            MM = '00'
            if minutes < 10:
                SS = '0' + str(minutes)
            else:
                SS = str(minutes)
        else:
            detik = minutes // 60
            if detik < 10:
                MM = '0' + str(detik)
            else:
                MM = str(detik)
        sekon = minutes % 60
        if sekon < 10:
            SS = '0' + str(sekon)
        else:
            SS = sekon
    return f"{HH}:{MM}:{SS}"