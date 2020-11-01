from Crypto.Cipher import AES
import binascii

ciphertext = input()

if len(ciphertext) == 32:
	cipher = AES.new('b1daf001f51d0b89c2619d52af0fe218', AES.MODE_ECB)

	print(cipher.decrypt(binascii.unhexlify(ciphertext)).decode('ASCII'))
