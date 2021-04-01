import string

def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
            
    return letters


def count_words(text):
    words = 1
    for i in range(len(text)):
        if text[i] == " ":
            words += 1
        
    return words


def count_sentences(text):
    sentences = 0
    ending = [".", "!", "?"]
    for i in range(len(text)):
        if text[i] in ending:
            sentences += 1
    
    return sentences
            

def grading(letters, words, sentences):
    L = float(letters)*100/float(words)
    S = float(sentences)*100/float(words)
    grading = .0588 * L - 0.296 * S - 15.8
    return round(grading)
    

text = input("Text: ")
grade = grading(count_letters(text), count_words(text), count_sentences(text))

if grade<1:
    print("Before Grade 1")
    
elif grade>=16:
    print("Grade 16+")
    
else:
    print(f"Grade {grade}")





