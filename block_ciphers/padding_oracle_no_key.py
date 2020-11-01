from Crypto.Cipher import AES
import binascii

def decrypt(key, iv, message):
        cipher = AES.new(key, AES.MODE_CBC, iv)

        return cipher.decrypt(message)


def check_padding(message):
        pad = message[len(message)-1]
        for i in range(pad):
                if message[len(message)-1-i] != pad:
                        return 'Bad'

        if pad > 0 and pad < 17:
                return 'Good'
        else:
                return 'Bad'

message = binascii.unhexlify(input())

message = decrypt('<redacted>', '<redacted>', message)

print(check_padding(message))

