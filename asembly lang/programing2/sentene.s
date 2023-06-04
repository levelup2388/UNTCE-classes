//nicholasBright@my.unt.edu
	.data
	.type	s, %object
s:
    .asciz "this is a test For code"

	.text
	.global main
	.arch armv8-a+fp+simd
	.type main, %function
space:
	ADD		X2, X2, #1				//word count++
	ADD		X1, X1, #1				//i++
	ADD 	X4, X0, X1				//Address of s[i]=x4
	LDURB	W5,[X4, #0]				//'s[i]'=w5
	CMP		W5,#97					//If W5 is upercase break
	B.LT	L1
upper:
	SUB		W5, W5,	#32				//subtracts asci value of w5 by 32
	STURB	W5,[X4,	#0]				//store new 32 in string
	B		EOT

main:
	ADRP 	X0, s
	ADD 	X0, X0, :lo12:s			//Loads string into s
	ADD 	X1, XZR, XZR			//i=0
	ADD 	X2, X1, #1				//Word count=1
	ADD 	X4, X0, X1				//Address of s[i]=x4
	LDURB	W5,[X4, #0]				//'s[i]'=w5
	ADD		X1, X1, #1				//i++
	CMP		W5,#97					//if W5 is lowercase break
	B.GE	upper

EOT:								//END of TEXT
	ADD 	X4, X0, X1				//Address of s[i]=x4
	LDURB	W5,[X4, #0]				//'s[i]'=w5

	CMP 	W5, #32					//W5<32
	B.LT	Exit

	CMP		W5, #32					//if(w5=32)break to space
	B.EQ	space

L1:
	ADD		X1, X1, #1				//i++
	B		EOT


Exit: