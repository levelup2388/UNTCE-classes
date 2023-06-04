READ ME
Fibonacci-
	X0 is the array address
	X1 is a 0 registry for further use
	X2 is 1 to be stored later
	X4 is address of v[i]
	X5 is i-1
	X6 is adress of v[i-1]
	X5 is i-1
	X7 is adress of v[i-2]
	X8 equals v[i-1]
	X9 equals v[i-2]
	x10 equals x8+x9
	x15 is i
Sentence-
	X0 is the address of the string
	x1=i
	x2= word count
	x4= adresss of s[i]
	x5= character at s[i]
	We assume that the first charcter is not a space, as well as that the charcters'{|}-DEL' are not used
vector-
	X1=i
	X2 =odd array adress
	x3= even array address
	x4= check variable
	x6= registry location of a[i]
	x7= registry location of b[i]
	x11= vector sum
	x22=2
	x24= 0 registry used in later functions
	in for1 loop
		x8=I*2+1
		x9=I*2+2
	in for2 loop
		x8=a[i]
		x9=b[i]
		x10=a[i]*b[i]
