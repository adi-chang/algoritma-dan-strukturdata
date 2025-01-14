koleksi_data = {
    1 : "satu",
    2 : "dua",
    3 : "tiga",
    4 : "empat", 
    5 : "lima"
}

print(f"data: {koleksi_data}")
print(f"tipe data: {type(koleksi_data)}")

print(f"5 : {koleksi_data.get(5)}")
print(f"6 : {koleksi_data.get(6, "tidak ditemukan")}")