//nicholasBright@my.unt.edu
      .data
      .type	num1, %object
num1:
      .type	num2, %object
num2:

      .text
      .global main
      .arch armv8-a+fp+simd
      .type main, %function

addhf:
	MOV		X30, X29
	MOV		X10, X2

	MOV		X5,X1
	BL		splithf
	MOV		X11, X1
	MOV		X12, X2
	MOV		X13, X3

	MOV		X5, X10
	BL		splithf
	MOV		X21, X1
	MOV		X22, X2
	MOV		X23, X3
check:
	CMP		X12,X22
	B.LT	less
	B.GT	greater
	MOV		X2, X12
L1:
	CMP		X13, X23		//make final sign
	MOV		X1, #0
	B.LT	less2
	B.GT	greater2
L2:
	CMP		X11, X21		//check sign(0=+, 1=-)
	B.NE	ne

	ADD		X3,X23,X13		//final matissa
L3:
	BL		normaizehf
	BL		combinehf

	BR		X29
less2:
	MOV		X1, X21
	B		L2
greater2:
	MOV		X1, X11
	B		L2
ne:
	SUB		X3, X23, X13
	B		L3
less:
	ADD		X12, X12, #1
	LSR		X13, X13, #1
	//align binary point
	B		check
greater:
	ADD		X22, X22, #1
	LSR		X23, X23, #1
	//align binary point
	B		check


mulhf:
	MOV		X30, X29
	MOV		X10, X2

	MOV		X5,X1
	BL		splithf
	MOV		X11, X1
	MOV		X12, X2
	MOV		X13, X3

	MOV		X5, X10
	BL		splithf
	MOV		X21, X1
	MOV		X22, X2
	MOV		X23, X3

	MUL		X3, X13, X23
	ADD		X2, X12, X22

	EOR		X1, X11, X21
/*	CMP		X11, X21
	B.EQ	EQ
	B.NE	NE2*/
L4:
	BL		normaizehf
	BL		combinehf

	BR		X29
/*EQ:
	MOV		X1, #0
	B		L4
NE2:
	MOV		X1, #1
	B		L4*/


main:
	BL	addhf
	BL	mulhf

Exit:
