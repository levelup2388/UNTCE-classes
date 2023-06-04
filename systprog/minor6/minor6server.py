import socket

# Parse the port number from the command line arguments
port = 123

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
server_address = ('localhost', port)
print(f'Starting up on {server_address}')
sock.bind(server_address)

# Listen for incoming connections
sock.listen(2)

# Wait for both players to connect
player1, addr1 = sock.accept()
print(f'Player 1 connected from {addr1}')
player2, addr2 = sock.accept()
print(f'Player 2 connected from {addr2}')

# Send the range of the number to guess to both players
min_num = 1
max_num = 100
player1.sendall(f'The number to guess is between {min_num} and {max_num}'.encode())
player2.sendall(f'The number to guess is between {min_num} and {max_num}'.encode())

# Process guesses from both players
while True:
    # Receive the guess from player 1
    guess = player1.recv(16)
    guess = int(guess.decode())

    # Check if the guess is correct
    if guess == num_to_guess:
        player1.sendall('You guessed the correct number!'.encode())
        player2.sendall('Player 1 guessed the correct number.'.encode())
        break

    # Send a message to player 1 if the guess was above or below the number
    if guess > num_to_guess:
        player1.sendall('Your guess was too high.'.encode())
    else:
        player1.sendall('Your guess was too low.'.encode())

    # Receive the guess from player 2
    guess = player2.recv(16)
    guess = int(guess.decode())

    # Check if the guess is correct
    if guess == num_to_guess:
        player1.sendall('Player 2 guessed the correct number.'.encode())
        player2.sendall('You guessed the correct number!'.encode())
        break

    # Send a message to player 2 if the guess was above or below the number
    if guess > num_to_guess:
        player2.sendall('Your guess was too high.'.encode())
    else:
        player2.sendall('Your guess was too low.'.encode())

# Close the socket
sock.close()


'''
import socket
import random
import select

# Set the port number
port = 12345

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
server_address = ('localhost', port)
print('Starting up on %s port %s' % server_address)
sock.bind(server_address)

# Listen for incoming connections
sock.listen(1)

# Wait for both clients to connect
connection1, client_address1 = sock.accept()
print('Connection from %s' % str(client_address1))
connection2, client_address2 = sock.accept()
print('Connection from %s' % str(client_address2))

# Choose a random number from 1 to 20
number = random.randint(1, 20)

# Send the range of numbers to guess to both clients
connection1.sendall(b'Guess a number from 1 to 20')
connection2.sendall(b'Guess a number from 1 to 20')

# Keep track of which client has won the game
winner = None

while winner is None:
    # Use the select() function to check if there is data available to read from either connection
    read_sockets, _, _ = select.select([connection1, connection2], [], [])

    for socket in read_sockets:
        # Receive the data from the client
        data = socket.recv(1024)

        # Convert the data to an integer
        guess = int(data)

        # Check if the guess is correct
        if guess == number:
            # Send a message to both clients indicating which client won the game
            winner_address = socket.getpeername()
            if winner_address == client_address1:
                connection1.sendall(b'You won!')
                connection2.sendall(b'Player 1 won the game')
            elif winner_address == client_address2:
                connection1.sendall(b'Player 2 won the game')
                connection2.sendall(b'You won!')
            winner = winner_address
        else:
            # Send a message to the client indicating if their guess was too high or too low
            if guess > number:
                socket.sendall(b'Your guess was too high')
            elif guess < number:
                socket.sendall(b'Your guess was too low')

# Close the connections
connection1.close()
connection2.close()
'''