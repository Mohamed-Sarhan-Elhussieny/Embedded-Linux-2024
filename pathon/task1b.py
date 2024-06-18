x = vowels = ('A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u')
y = input("Enter letter to search about: ")
i = 0

while i < len(x):
    if y is x[i]: 
        print("The letter is vowel")
        break
    i += 1
else: 
    print("The letter is not vowel")
