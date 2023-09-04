#countdown
def countdown(i):
    print(i)
    if i <= 0:  #Base case
        return
    else:
        countdown(i-1)  #Recursive case

countdown(5)


#stack trace
def greet(name):
    print("hello, " + name + "!")
    greet2(name)
    print("getting ready to say bye...")
    bye()


def greet2(name):
    print("how are you, " + name + "?")

def bye():
    print("ok bye!")

greet("Abebe")