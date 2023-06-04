//nicholasBright@my.unt.edu
	.data
	.type	v, %object
v:

	.text
	.global main
	.arch armv8-a+fp+simd
	.type main, %function

main:
	ADR 	X0, v
	ADD 	X0, X0, :lo12:v
	ADD 	X1, XZR, XZR 		//x1=0
	ADD 	X2, X1, #1			//x2=1
	ADD		X15, X1, #2			//x3=i=2
	STUR	X1, [X0, #0]		//stores x1 values in x0 registery
	STUR	X2, [X0, #8]		//stores values of x2 in x0 registry + 8 bit
for:
	SUB 	X16, X15, #11		//x16= i-11
	CBZ		X16, Exit			//if x16=0 exit

	ADD 	X4, X0, X15, LSL #3 //x4= adress of v[i]
	SUB		X5, X15, #1			//X5=i-1
	ADD 	X6, X0, X5, LSL #3  //x6= adress of v[i-1]
	SUB		X5, X5, #1			//X5=i-2
	ADD 	X7, X0, X5, LSL #3  //x7= adress of v[i-2]
	LDUR 	X8, [X6, #0]		//x8 = v[i-1]
	LDUR	X9, [X7, #0]		//X9 = v[i-2]

	ADD		X10, X9, X8			//X10 = X9+X8
	STUR	X10, [X4,#0]		//stores value of x10 in adress of v[i]

	ADD		X15, X15, #1		//i++
	B 		for

Exit:

