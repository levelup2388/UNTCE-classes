import socket

# set up the client
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 5555))

while True:
    # get the user's guess
    guess = input("Enter your guess: ")

    # send the guess to the server
    client.send(guess.encode())

    # receive the response from the server
    response = client.recv(1024).decode()

    # check if the game is over
    if response == "You guessed it!":
        print("You won!")
        break
    else:
        print(response)

# close the connection
client.close()
