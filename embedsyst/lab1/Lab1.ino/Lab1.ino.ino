int a_num;
int b_num;
int i;
int blink; 
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(WIO_BUZZER,OUTPUT);
  pinMode(WIO_KEY_A,INPUT_PULLUP);
  pinMode(WIO_KEY_B,INPUT_PULLUP);
  pinMode(WIO_KEY_C,INPUT_PULLUP);
}
/*Geeks for geeks code for fibonaci sequence
https://www.geeksforgeeks.org/c-program-for-n-th-fibonacci-number/ */
int fib(int n){
  if (n <= 1)
      return n;
  return fib(n-1) + fib(n-2);
}
//////////////////////////////////////////////////////////////
/*
buzzer code, and led blink taken from arduino example codes
*/
void loop() {
 digitalWrite(LED_BUILTIN, LOW);   
  // put your main code here, to run repeatedly:
  if(digitalRead(WIO_KEY_C)==LOW){
    analogWrite(WIO_BUZZER, 128);
    delay(100);
    analogWrite(WIO_BUZZER, 0);
    delay(100);
    a_num=0;
    b_num=0;
  }
  else if(digitalRead(WIO_KEY_A)==LOW){
    a_num++;
    analogWrite(WIO_BUZZER, 128);
    delay(100);
    analogWrite(WIO_BUZZER, 0);
    delay(100);
    blink=1;
    for(i=1; i<=a_num; i++){
      blink = blink * i;
    }
    for(i=1;i<=blink;i++){
      digitalWrite(LED_BUILTIN, HIGH);  
      delay(500);                      
      digitalWrite(LED_BUILTIN, LOW);   
      delay(500);
    }
  }
  else if(digitalRead(WIO_KEY_B)==LOW){
    analogWrite(WIO_BUZZER, 128);
    delay(100);
    analogWrite(WIO_BUZZER, 0);
    delay(100);
    blink = fib(b_num);
    b_num++;
    for(i=1;i<=blink;i++){
      digitalWrite(LED_BUILTIN, HIGH);  
      delay(500);                      
      digitalWrite(LED_BUILTIN, LOW);   
      delay(500);
    }
  }
  delay(100);
}
