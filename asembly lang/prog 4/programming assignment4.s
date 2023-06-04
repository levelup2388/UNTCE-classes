//nicholasBright@my.unt.edu
	.data
num1:
	.hword 0
num2:
	.hword 0
fadd:
	.hword 0
fmul:
	.hword 0
myadd:
	.hword 0
mymul:
	.hword 0
	.text
	.global main
	.arch armv8-a+fp16+simd
	.type main, %function
splithf:

	MOV		X1, #0x8000		//Mask for sign
	AND		X1, X0, X1		//gives us our sign

	MOV		X2, #0x7C00		//mask for exponet
	AND		X2, X0, X2		//masks off the number to gather exponent
	LSR		X2, X2, #10		//shifts exponent properly
	SUB		X2, X2, #15		//gives us exponet

	MOV		X3, #0x03FF		//mask for mantissa
	AND		X3, X0, X3		//gives us fraction
	ORR		X3, X3, #0x0400	//gives us mantissa

	BR 		X30				//return

combinehf:
	MOV		X0, #0x03FF		//mask for mantisa
	AND		X3, X0, X3		//sets mask on matisa

	ADD		X2, X2, #15		//adds bias to exponent
	LSL		X2, X2, #10		//shifts exponet to correct position

	ORR		X0, X1, X2		//sets sign and exponent on x0
	ORR		X0, X0, X3		//sets mantisa on x0

	BR		X30				//return
normalizehf:
	CLZ		X4, X3			//leading zeros of mantisa on x4
	SUB		X4, X4, #48		//delete extra bits of x register
	MOV		X5, #5
	CMP		X4, X5			//checks if has ideal leading zeros
	B.GT	g1				//break greater 1
	B.LT	Less1			//break less1
	BR		X30				//return
g1:
	SUB		X4, X4, X5		//subtract leading zeros-5
	LSL		X3, X3, X4		//shifts mantisa by that amount
	SUB		X2, X2, X4		//sub exponent by that amount
	BR		X30				//return
Less1:
	SUB		X4, X5, X4		//gathers differnec in leading zeros needed
	LSR		X3, X3, X4		//sets mantisa
	ADD		X2, X2, X4		//sets exponent
	BR		X30				//return

addhf:
	MOV		X29, X30		//sets x29 to return adress
	MOV		X10, X2			//sets x10 to second number

	MOV		X0,X1			//sets x0 to first number
	BL		splithf			//break
	MOV		X11, X1			//sign
	MOV		X12, X2			//exponent
	MOV		X13, X3			//mantissa

	MOV		X0, X10			//sets x0 to second number
	BL		splithf			//break
	MOV		X21, X1			//sign
	MOV		X22, X2			//exponent
	MOV		X23, X3			//mantissa


	CMP		X12,X22			//compare exponents to set them properly
	B.LT	less			//break
	B.GT	greater			//break
L1:
	CMP		X13, X23		//make final sign
	B.LT	less2			//break
	B.GT	greater2		//break
L2:
	CMP		X11, X21		//compare signs to see if needing to subtract or add
	B.GT	greater3		//break
	B.LT	less3			//break
	ADD		X3, X13, X23	//adds mmantissa
L3:
	BL		normalizehf		//break
	BL		combinehf		//break
	BR		X29				//return

greater:
	SUB		X5, X12, X22	//sub exponets
	ADD		X22, X22, X5	//adds differnce
	MOV		X2, X22			//sets that to final exponent
	LSR		X23,X23, X5		//shifts x23 by that exponet
	B		L1				//return
less:
	SUB		X5, X22, X12	//sub exponents
	ADD		X12, X12, X5	//add differnce to first expopnet
	MOV		X2, X12			//sets final exponent to that
	LSR		X13,X13, X5		//shifts mantisa by differnce
	B		L1				//return
greater2:
	MOV		X1, X11			//sets final sign to first sign
	B		L2				//return
less2:
	MOV		X1, X21			//sets final sign to second sign
	B		L2				//return
less3:
	SUB		X3, X13, X23	//subtract first mantisa by second
	B		L3				//return
greater3:
	SUB		X3, X23, X13	//subtract second mantisa by first
	B		L3				//return

mulhf:
	MOV		X29, X30		//sets return adress to x29
	MOV		X10, X2			//sets x10 to second number

	MOV		X0,X1			//sets x0 to first number
	BL		splithf			//break
	MOV		X11, X1			//sign
	MOV		X12, X2			//exponent
	MOV		X13, X3			//mantissa

	MOV		X0, X10			//sets x0  to second number
	BL		splithf			//break
	MOV		X21, X1			//sign
	MOV		X22, X2			//exponent
	MOV		X23, X3			//mantissa

	MUL		X3, X13, X23	//multiply mantissa
	ADD		X2, X12, X22	//add exponent

	EOR		X1, X11, X21	//xor sign

	BL		normalizehf		//break
	SUB		X2, X2, #10		//set exponent properly
	BL		combinehf		//break

	BR		X29				//return


main:
	MOV		X1, #42			//set first number to 42
	MOV 	X2, #-9			//sets second number to -9
	SCVTF	H1, X1			//sets h1 to x1
	SCVTF	H2, X2			//sets h2 to x2
	ADRP	X14, num1				//sets adress for all answers->>>
	ADD		X14, X14, :lo12:num1
	ADRP	X15, num2
	ADD		X15, X15, :lo12:num2
	ADRP	X16, fadd
	ADD		X16, X16, :lo12:fadd
	ADRP	X17, fmul
	ADD		X17, X17, :lo12:fmul
	ADRP	X18, myadd
	ADD		X18, X18, :lo12:myadd
	ADRP	X19, mymul
	ADD		X19, X19, :lo12:mymul	//-------------------------
	STUR	H1, [X14]		//store value of h1 in num1
	STUR	H2, [X15]		//store value of h2 in num2

	FADD	H3, H2, H1		//add h2,h1
	FMUL	H4, H2, H1		//mul h1,h2

	STUR	H3,[X16]		//store h3 in fadd
	STUR	H4,[X17]		//store h4 in fmul


	LDRH	W1,[X14]		//reset x1
	LDRH	W2,[X15]		//reset x2
	BL		addhf			//break
	STUR	X0, [X18]		//store value into myadd

	LDRH	W1,[X14]		//reset x1
	LDRH	W2,[X15]		//reset x2
	BL		mulhf			//break
	STUR	X0, [X19]		//store value in mymul
Exit:
