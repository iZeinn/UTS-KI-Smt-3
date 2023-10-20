from Crypto.Cipher import AES
from secrets import token_bytes

key = token_bytes(16)

def encrypt(msg):
    chiper = AES.new(key, AES.MODE_EAX)
    nonce = chiper.nonce
    chiperText, tag = chiper.encrypt_and_digest(msg.encode('ascii'))
    return nonce, chiperText, tag

def decrypt(nonce, chiperText, tag):
    chiper = AES.new(key, AES.MODE_EAX, nonce=nonce)
    plaintext = chiper.decrypt(chiperText)
    try:
        chiper.verify(tag)
        return plaintext.decode('ascii')
    except ValueError:
        return False

nonce, chiperText, tag = encrypt(input('Masukkan text: '))
plaintext = decrypt(nonce, chiperText, tag)
print(f'Chiper text: {chiperText}')
if plaintext:
    print(f'Plain text: {plaintext}')
else:
    print('Pesan salah')
