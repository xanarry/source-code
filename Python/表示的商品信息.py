expiration = [12, 10, 2009]
print("This milk carton will expire on %d/%d/%d" % (expiration[0], expiration[1], expiration[2]))
milk_carton = {}
milk_carton["expiration_date"] = expiration
milk_carton["fl_oz"] = "12L"
milk_carton["cost"] = 100
milk_carton["name"] = "dell"
vals = milk_carton.values()
print(list(vals))
