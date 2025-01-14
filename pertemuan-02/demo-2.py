from random import randint


list_data = [randint(1, 100) for _ in range(10)]

print(f"data awal: {list_data}")

print("sorting ...")
list_data.sort()

print(f"data after sort: {list_data}")