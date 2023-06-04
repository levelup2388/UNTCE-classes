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
splithf:
	MOV		X0, #17664

	//FCVT	S1, H1
	//FCVTAS	X0, S1
	MOV		X1, #32768
	AND		X1, X0, X1		//gives us our sign

	MOV		X2, #31744
	AND		X2, X0, X2
	LSR		X2, X2, #10
	SUB		X2, X2, #15		//gives us exponet

	MOV		X3, #1023
	AND		X3, X0, X3		//gives us fraction
	ORR		X3, X3, #1024	//gives us mantissa

	BR 		X30

combinehf:
	MOV		X0, #31744
	AND		X3, X0, X3

	ADD		X2, X2, #15
	LSL		X2, X2, #10

	ORR		X0, X1, X2
	ORR		X0, X0, X3

	BR		X30
normalizehf:
	MOV		X0, #31744
	AND		X0, X0, X3
main:
	MOV		X1, #52
	MOV 	X2, #1356
	SCVTF	S1, X1
	SCVTF	S2, X2
	FCVT	H1, S1
	FCVT	H2, S2
	ADRP	X11, num1
	ADD		X11, X11, :lo12:num1
	ADRP	X12, num2
	STUR	H1, [X11]
	STUR	H2, [X12]
	BL		splithf
	BL		combinehf
	BL		normalizehf

Exit: