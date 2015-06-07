def stunum_generator(start_year, end_year, start_major, end_major, start_num, end_num):
    for y in range(start_year, end_year + 1):
        for m in range(start_major, end_major + 1):
            for n in range(start_num, end_num + 1):
                yield(str(y) + str(m).zfill(3) + str(n).zfill(3))

generator = stunum_generator(2013, 2014, 0, 10, 0, 10)
for i in range(100):
    print(generator.__next__())
