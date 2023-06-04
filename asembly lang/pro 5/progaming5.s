//nicholasBright@my.unt.edu
.data

a:
	.single 1.5,2.6,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1,0.0, 0.0		//first vector

b:
	.single 10.1,11.1,12.2,13.3,14.4,15.5,16.6,17.7,18.8,19.9,0.0, 0.0//second vector
c:
	.single 0.0, 0.0, 0.0, 0.0		//store vector
answer:
	.single							//answer



.text
	.global main
	.arch armv8-a+fp16+simd
	.type main, %function



main:
	// Address of a
	ADRP X21, a
	ADD X21, X21, :lo12:a
	MOV	X1, X21					//store adress of a in x1

	// Address of b
	ADRP X22, b
	ADD X22, X22, :lo12:b
	MOV	X2, X22					//store adress of b in x2

	// Address of c
	ADRP X23, c
	ADD X23, X23, :lo12:c

	//adress of answer
	ADRP X24, answer
	ADD X24, X24, :lo12:answer

	MOV	 X0, #16				//increment
	MOV	 X12, #0				//loop count
	LDUR Q2, [X23]				//load storage vector in q2
loop:
	CMP	X12, #4					//check if loop has gone 4 or more times
	B.GE	L1
	LDUR Q0, [X1]				//store 4 values from a in Q0
	LDUR Q1, [X2]				//store 4 values from b in Q1
	FMUL V0.4S, V0.4S,V1.4S		//mul Q0*Q1
	FADD V2.4S, V2.4S, V0.4S	//add that multiplication to store value

	ADD	X1, X1, X0				//increase location to grab a
	ADD	X2, X2, X0				//increase location to grab b
	ADD	X12, X12, #1			//increment loop
	B loop						//loop
L1:
	FADDP V2.4S, V2.4S, V2.4S	//add internals of storage vector
	FADDP S11, V2.2S			//add last 2 of storage vectors
	STUR S11,[X24]				//store value in answer

fini:
	NOP