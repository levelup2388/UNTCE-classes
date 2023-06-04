//nicholasBright@my.unt.edu
	.data
	.type	v, %object
v:
	.xword 5,4
	.type	c, %object
c:
	.text
	.global main
	.arch armv8-a+fp+simd
	.type main, %function

pow:
	CMP		X4, X5			//i>n break
	B.LE	L2

	BR		X30				//else return
L2:
	FMUL	D25, D25, D26	//D25= sumation of power	D26 is base of power

	ADD		X4, X4, #1		//i++
	B		pow


fact:
	SUB		SP,SP,#16   		// Save return address and n on stack
	STUR	X30, [SP, #8]   	// Store return address on the stack
	STUR 	X3, [SP,#0]   	// Store n on stack
	SUBS 	XZR,X3,#1   		// Compare n and 1
	B.GE 	L1           	// If n>=1, go to L1

	ADD 	SP, SP, #16    	// Pop stack, don't bother restoring values
	BR 		X30             	// Return
L1:
	SUB 	X3,X3,#1     		// n=n-1
    BL 		fact           	// Call fact(n-1)
A1:
	LDUR 	X30, [SP, #8]  	// Restore caller's return address
	LDUR 	X3, [SP, #0]   	// Restore caller's n
    ADD 	SP,SP,#16    		// Pop stack
    MUL 	X1,X3,X1      	// Return n*fact(n-1)

    BR 		X30             // Return
bcos:
	MOV		X28, X30		//sets x28 to return adress
cos:
	CMP		X2,X0			// n<a go to L3
	B.LE	L3

	BR		X28			//else return
L3:
	LSL		X3, X2, #1		//X3=n*2
	MOV		X5, X3			//X5=2n
	MOV		X1, #1			//fact=1
	//CBZ		X3, zero		//if n =0 break to 0 case
    BL		fact
	SCVTF	D21, X1			// D21(denom) = X1(factorial)

   	MOV		X4, #1			//x4= i=1
   	MOV		X22, #1			//x22=1
   	SCVTF	D25, X22		//D25=1
   	FMOV	D26, D10		//D26 =x
   	BL 		pow				//link branch to pow
   	FMOV	D6, D25			//store value of function in D6

    MOV		X4, #1			//x4= i=1
    MOV		X5, X2			//limit of pow =n
   	MOV		X22, #-1		//x22=-1
   	SCVTF	D25, X4			//D25= 1
   	SCVTF	D26, X22		//D26=-1
   	BL 		pow				//branch link to pow
   	FMOV	D5, D25			//store value of function in D5

    FMUL	D7, D5, D6		//D7(numerator) = D5(-1^n)*D6(x^2n)
	FDIV	D8, D7, D21		//D8(equation)= D7/D21
	FADD	D11, D11, D8	//D11(summation)= D11+D8
	STUR	D11, [X18, #0]		//D11 stored in first member location of c
	ADD		X2, X2, #1		//n++
	B	cos


main:
	ADRP	X19, v				//X19= adress of v
	ADD		X19, X19, :lo12:v	//X19= beging adress of v
	ADR		X18, c
	ADD		X18, X18, :lo12:c	//X18 = first member adress of c
    LDUR   	X0, [X19, #0]			//X0(a)=1st member of v
    MOV		X2, XZR			//n=0
    LDUR	X21, [X19, #8]	//X21 used to set D values = second meber of v =x
    SCVTF	D10, X21		//D10 =x=4
    FMOV 	D11,XZR			//D11 = sum=0
	BL		bcos
	B		Exit
Exit:
