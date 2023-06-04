#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


/*
Post examples on threads
1. Create a function that
creates the field.
2. Create a function to
display scores. I think on the
side look better than above
the field.
3. Create a function to move
a player or the rabbit. (Blank
current location and print at
new location)
4. You may want to use
double the horizontal as it
will make the screen look
better.
5. Create a function to
display items. For initial
testing just have it do a print.
Then once you get other
things working have it send
the move to all players, the
rabbit and possibly print on
the server.
6. Use the following macros
to position the cursor. (These
are based on VT100
terminals)
#define clear() printf("\
033[H\033[J")
#define gotoxy(x,y)
printf("\033[%d;%dH", (y),
(x))
7. Place the cursor at the
bottom or clear the screen
when you exit. It will make
the screen nicer when the
program ends.
8. Create the rabbit and
possibly one player working
as part of the server before
attempting to split it into
client and server. This way
you can verify the logic
without having to worry
about the socket.*/
	return 0;
}