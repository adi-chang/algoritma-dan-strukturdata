if __name__ == '__main__':
    
    s1 = set()
    s2 = {1,2,3,4,5,6,7,8,9}

    print(f"tipe dari s1: {type(s1)}")

    s1.add(1)
    s1.add(1)
    s1.add(1)
    s1.add(2)
    s1.add(3)
    s1.add(4)
    s1.add(5)

    print(f"isi variable s1: {s1}")
    print(f"isi variable s2: {s2}")

    s3 = s1.union(s2)

    print(f"isi variable s3: {s3}")

    s4 = s1.intersection(s2)

    print(f"isi variable s4: {s4}")

    s5 = s1.difference(s2)
    print(f"isi variable s5: {s5}")

    s6 = s2.difference(s1)
    print(f"isi variable s6: {s6}")



