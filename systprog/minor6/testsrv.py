import socket
import random

# set up the server
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('localhost', 5555))
server.listen()

# generate a random number for the clients to guess
number = random.randint(1, 100)

# keep track of the number of guesses made
num_guesses = 0

# keep accepting connections from clients
while True:
    client, addr = server.accept()
    print(f"Received a connection from {addr}")

    # receive the client's guess
    guess = client.recv(1024).decode()
    guess = int(guess)

    # check if the guess is correct
    if guess == number:
        client.send("You guessed it!".encode())
        break
    else:
        client.send("Wrong! Try again.".encode())

    # increment the number of guesses
    num_guesses += 1

# close the connection
client.close()
server.close()