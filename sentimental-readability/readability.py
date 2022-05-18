# TODO

count_letter = 0
count_word = 1
count_sentence = 0

text = input("Type in some text: ")
text_length = len(text)

# count the number of letters in the text
# isalpha() method returns True if all the characters are alphabet letters
for i in range(text_length):
    if(text[i].isalpha()):
        count_letter += 1

# count the number of words in text
# isspace() method returns True if all the characters in a string are whitespaces, otherwise Fasle
    if (text[i].isspace()):
        count_word += 1

# count the number of sentence
    if(text[i] == '.' or text[i] == '?' or text[i] == '!'):
        count_sentence += 1

# average_number_of_letters = L
# average number of numbers = S
# .0588 * L - 0.296 * S - 15.8
calculation = (0.0588 * count_letter / count_word * 100) - (0.296 * count_sentence / count_word * 100) - 15.8 
index = round(calculation)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")