from Crypto.Cipher import AES

def pad(message):
	pad = 16 - (len(message) % 16)
	if pad != 0:
		message = message + chr(pad)*pad
	else:
		message = message + chr('\x10')*pad
	return message

def encrypt(key, message):
	cipher = AES.new(key, AES.MODE_ECB)

	return cipher.encrypt(pad(message))

data = input()

message = "Your data is: " + data + " and the flag is: <redacted>"

print(encrypt('<redacted>', message).hex())
