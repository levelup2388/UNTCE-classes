
#define BIT_SET  1
#define BIT_CLEAR 2
#define BIT_TOGGLE 3

int get_operation(int* op, unsigned short* bit);
short execute_operation(int operation, unsigned short bit, unsigned short value);
void display(unsigned short value);
