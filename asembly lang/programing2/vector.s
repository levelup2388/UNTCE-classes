//nicholasBright@my.unt.edu
	.data
	.type	A, %object
A:
	.type	B, %object
B:

	.text
	.global main
	.arch armv8-a+fp+simd
	.type main, %function
main:
	ADR 	X2, A
	ADD 	X2, X2, :lo12:A		//sets x2 to memory adress for A
	ADR 	X3, B				//sets x3 to memory adress for B
	ADD		X1, XZR, XZR		//x1=i=0
	ADD		X11, XZR, XZR		//Vecotr sum=x11=0
	ADD 	X24, XZR, XZR		//x24 = 0= 0register used in later functions
for1:
	SUB		X4, X1, #5
	CBZ		X4, L1				//check if I<5

	ADD		X6, X2, X1, LSL #3	//Sets X6 to  register loctaion of A[i]
	ADD		X7, X3, X1, LSL #3	//Sets X7 to  register loctaion of B[i]
	ADD		X22, X24, #2		//X22 =2
	MUL		X8, X1, X22			//X8 = I*2
	MUL		X9, X1, X22			//X9 = I*2
	ADD		X8, X8, #1			//X8 = I*2 +1
	ADD		X9, X9, #2			//X9 = I*2 +2
	STUR	X8, [X6, #0]		//Store value of X8 in A[i]
	STUR	X9, [X7, #0]		//Store value of X( in B[i]

	ADD 	X1, X1, #1			//I++
	B		for1				//loop
L1:
	ADD		X1, XZR, XZR		//i=0
for2:
	SUB		X4, X1, #5
	CBZ		X4, Exit			//Check if I<5

	ADD		X6, X2, X1, LSL #3	//set X6 to registery ocation for A[i]
	ADD		X7, X3, X1, LSL #3	//set X7 to registery ocation for B[i]
	LDUR	X8, [X6, #0]		//loads value of A[i] to x8
	LDUR	X9, [X7, #0]		//loads value of B[i] to x9
	MUL		X10, X8, X9			//X10 = A[i]*B[i]
	ADD		X11, X11, X10		//vector sum/x11 = X11 +X10

	ADD		X1, X1, #1			//I++
	B 		for2				//Loop

Exit: