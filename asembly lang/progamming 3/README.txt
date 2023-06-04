READ ME
Program built and tested nativly on DS-5 eclipse

Answer for cos stored in memory location x19 or D11

Starting at main and following loop
X19= starting adress of data type v in which the memory position is set to a and second set to x
x18= starting adressres of data type c in which the answer for the equation will be stored each loop and then store the 
	final answer all in the same memory location, this could changed later to store each loop one by one instead 
	of deleting it however this seems unecessary for this use. 
X0 =a
x2=n
X21=x which is then used to set D10 to X
D11= 0 summation loop which the finally answer accumaltes to
X28= branch location in main when cos is called
X3, X5= n*2
X4=i
X1 starts at one and once factorial is called x1 is used to store value of factorial function
Then x1 is used to store the value of the factorial function inputed to D21

For X^2n
X4,i and x22 set to 1
D25 set to 1
D26 =x
sent to pow function
answer is then stored in D6

For (-1)^n
X4,i set to 1
X5= n
X22 set to -1 and used to set D26 to -1
X4 used to set D25 to 1
sent to pow function
answer stored in D5

D5(-1^n)*D6(x^2n) stored in D7
D7((-1^n)*(x^2n))/ D21(2n!) stored in D8
D11 stored itself plus D8
then D11 is stored in the first position of data type c


IN POW FUNCTION
D5 stores the product of itself and D26



