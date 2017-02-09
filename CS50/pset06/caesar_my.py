lib = [' ', '!', '"', '#', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
       ':', ';', '=', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
       'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
       'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', 'Ё', 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ж', 'З',
       'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'а',
       'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ',
       'ъ', 'ы', 'ь', 'э', 'ю', 'я', 'ё', '№']
l = len(lib)

text = input('Text: ')
key = int(input('Key: '))
op = input('Operation [code or decode]: ')

def decode():
    for x in text:
        index = lib.index(x)
        index = (index - key) % l
        index = index if index > -1 else -index
        print(lib[index], end='')
        
def code():
    for x in text:
        index = lib.index(x)
        index = (index + key) % l
        print(lib[index], end='')

if 'code' == op:
    code()
elif 'decode' == op:
    decode()
else:
    print('No such operation!')