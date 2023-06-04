	.data
	.type	v, %object
	.size	v, 3

v:
	.xword 1, 2, 3

	.text
	.global main
	.arch armv8-a+fp+simd
	.type main, %function

main:
	ADRP X0, v
	ADD X0, X0, :lo12:v
	LDUR X1, [X0, #0]
	LDUR X2, [X0, #8]
	ADD X1, X1, X2
	LDUR X2, [X0, #16]
	ADD X1, X1, X2
Exit: