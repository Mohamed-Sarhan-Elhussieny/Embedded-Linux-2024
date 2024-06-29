x = [1, 4, 2, 3, 3, 4, 4, 4]
y = int(input("Enter num you need to search about repetition: "))
i = 0
count = 0

while i < len(x):  # Ensure the loop runs within the bounds of the list
    if y == x[i]:
        count += 1
    i += 1  

print("The number of repetitions:", count)
