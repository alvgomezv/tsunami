def obj_to_hex(file_path):
    with open(file_path, 'rb') as file:
        data = file.read()
    
    hex_text = ''.join('\\x{:02x}'.format(byte) for byte in data)
    return hex_text

obj_file_path = 'shellcode.obj'
hex_text = obj_to_hex(obj_file_path)
print(hex_text)
