MAIN:
	X1, W1, H1 store 42
	X2, W2, H2 store 42
	X14 address of num1
	X15 address of num2
	X16 address of fadd
	X17 address of fmul
	X18 address of myadd
	X19 address of mymul
	H3 store computer add of h1, h2
	h4 stores computers mul of h1, h2
	x0 stores value from addhf and mulhf
splithf:
	x0, input number
	X1, mask of sign and then final sign
	x2, mask for exponent then final exponent
	x3, mask for matissa  and final mantissa
	x30, return address
combinehf:
	x0, mask for mantissa then final number
	x3, mantissa
	x2, exponent
	x1, sign
	x30, return address
normalizehf:
	x3, mantissa
	x2, exponent
	x1, sign
	x4, leading zeros
	x5, 5
	x30, return address
addhf:
	x0, number sent into split and final answer
	x3, mantissa
	x2, second number then exponent
	x1, first number then sign
	x5, differnce of exponents
	x11, first sign
	x12, first exponent
	x13, first mantissa
	x21, second sign
	x22, second exponent
	x23, second mantissa
	X29, return address
	x30, return address
mulhf:
	x0, number sent into split and final answer
	x3, mantissa
	x2, second number then exponent
	x1, first number then sign
	x11, first sign
	x12, first exponent
	x13, first mantissa
	x21, second sign
	x22, second exponent
	x23, second mantissa
	X29, return address
	x30, return address
	
	