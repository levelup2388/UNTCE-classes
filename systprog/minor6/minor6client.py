import socket

# Parse the server's URL and port number from the command line arguments
server_url = 'localhost'
server_port = 12345
#server_url = sys.argv[1]
#server_port = int(sys.argv[2])

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the server
server_address = (server_url, server_port)
print(f'Connecting to (server_url, server_port)')
sock.connect(server_url, server_port)

# Receive messages from the server and display them
while True:
    data = sock.recv(16)
    if not data:
        break
    print(data.decode())
# Allow the player to enter numbers and send them to the server as a guess
while True:
    guess = input('Enter your guess: ')
    sock.sendall(guess.encode())

# Close the socket
sock.close()


'''
import socket

# Set the server's URL and port number
server_url = 'localhost'
server_port = 12345

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the server
server_address = (server_url, server_port)
print('Connecting to %s port %s' % server_address)
sock.connect(server_address)

# Receive the range of numbers to guess from the server
data = sock.recv(1024)
print(data.decode())

# Keep playing the game until the player wins or quits
while True:
    # Prompt the player to enter a guess
    guess = input('Enter a guess: ')

    # Check if the player wants to quit the game
    if guess == 'quit':
        break

    # Send the player's guess to the server
    sock.sendall(bytes(guess, 'utf-8'))

    # Receive a response from the server
    data = sock.recv(1024)
    print(data.decode())

    # Check if the player has won the game
    if data == b'You won!':
        break

# Close the connection
sock.close()
'''