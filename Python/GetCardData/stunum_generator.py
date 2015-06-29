def generator(start_year, end_year, start_major, end_major, start_num, end_num):
    '''创建给定范围内学号的生成器'''
    for y in range(start_year, end_year + 1):
        for m in range(start_major, end_major + 1):
            for n in range(start_num, end_num + 1):
                yield(str(y) + str(m).zfill(3) + str(n).zfill(3))