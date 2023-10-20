def encrypt(text, shift):
    teks_enkripsi = ""
    for char in text:
        if char.isalpha():
            is_upper = char.isupper()
            char = char.lower()
            encrypted_char = chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            if is_upper:
                encrypted_char = encrypted_char.upper()
            teks_enkripsi += encrypted_char
        else:
            teks_enkripsi += char
    return teks_enkripsi

def decrypt(encrypted_text, shift):
    teks_dekripsi = ""
    for char in encrypted_text:
        if char.isalpha():
            is_upper = char.isupper()
            char = char.lower()
            decrypted_char = chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
            if is_upper:
                decrypted_char = decrypted_char.upper()
            teks_dekripsi += decrypted_char
        else:
            teks_dekripsi += char
    return teks_dekripsi

# Input teks yang akan dienkripsi
text = input("Masukkan kalimat: ")
shift = 3

# Enkripsi teks
encrypted_text = encrypt(text, shift)
print("Teks Terenkripsi:", encrypted_text)

# Dekripsi teks
decrypted_text = decrypt(encrypted_text, shift)
print("Teks Terenkripsi:", decrypted_text)
