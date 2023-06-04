#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
#define ROWS 10
#define COL 10

void displayFeild(int rpos,int p1pos,int p2pos,int p3pos,int p4pos,int  jscore, int sscore, int ascore, int p4score,char* p1,char* p2,char* p3,char* p4){
	int spot=0;
	printf("- 1 2 3 4 5 6 7 8 9 10 -\n");
	for (int i= 0; i < 10; i++) { // Loop through each row
	printf("- ");
		for (int j = 0; j < 10; j++) {// Loop through each column
		//printf("%d ",spot);
			if(rpos==spot)printf("# ");
			else if(p1pos==spot)printf("$ ");
			else if(p2pos==spot)printf("%c ",'%');
			else if(p3pos==spot)printf("@ ");
			else if(p4pos==spot)printf("! ");
			else printf("  ");
			spot++;
		}
		printf(" -");
		if(i==3)printf("%10c Rabbit worth 50 pts\n",'#');
		else if(i==4)printf("%10c %s %10d\n",'$',p1, jscore);
		else if(i==5)printf("%10c %s %11d\n",'%',p2,sscore);
		else if(i==6)printf("%10c %s %10d\n",'@',p3,ascore);
		else if(i==7)printf("%10c %s %10d\n",'!',p4,p4score);
		else printf("\n");
	}
	printf("-----------------------\n");
	return;
}/*2. Create a function to
display scores. I think on the
side look better than above
the field.*/
/*
void displayscores(int jscore, int sscore, int ascore, int p4score,char* p1,char* p2,char* p3,char* p4){
	printf("# Rabbit worth 50 pts\n");
	printf("$ %s %10d\n",p1, jscore);
	printf("%c %s %11d\n",'%',p2,sscore);
	printf("@ %s %10d\n",p3,ascore);
	printf("! %s %10d\n",p4,p4score);
return;
}*/
/*3. Create a function to move
a player or the rabbit. (Blank
current location and print at
new location)*/
void printmovement(){
	printf("movement options(lines show direction of movement):\n");
	printf("\\ | /\n");
	printf(" 789 \n");
	printf("-4 6-\n");
	printf(" 123 \n");
	printf("/ | \\");
	printf("\n");
	return;
}
int movementpos(int move,int ppos){
//,bool p1Pos[][COL],bool p2Pos[][COL],bool p3Pos[][COL],bool p4pos[][COL]){
	if(move==1){
		ppos+=9;
	}
	else if(move==2){
		ppos+=10;
	}
	else if(move==3){
		ppos+=11;
	}
	else if(move==4){
		ppos--;
	}
	else if(move==6){
		ppos++;
	}
	else if(move==7){
		ppos-=11;
	}
	else if(move==8){
		ppos-=10;
	}
	else if(move==9){
		ppos-=9;
	}
	return ppos;
}
void notaken(int* rpos ,int* p1pos ,int* p2pos,int* p3pos ,int* p4pos, int start){
	if(start==0){
	while(*rpos==*p1pos||*rpos==*p2pos||*rpos==*p3pos||*rpos==*p4pos)*rpos = rand() % 100;
	while(*p1pos==*p2pos||*p1pos==*p3pos||*p1pos==*p4pos)*p1pos = rand() % 100;
	while(*p2pos==*p1pos||*p2pos==*p3pos||*p2pos==*p4pos)*p2pos = rand() % 100;
	while(*p3pos==*p1pos||*p3pos==*p2pos||*p3pos==*p4pos)*p3pos = rand() % 100;
	while(*p1pos==*p4pos||*p2pos==*p4pos||*p3pos==*p4pos)*p4pos = rand() % 100;
	}
	return;
}
bool bound(int ppos, int move){
	int modpos= ppos%10;
	if((ppos>=0)&&(ppos<=9)){
		if(move==7||move==8||move==9){
			return false;
		}
	}
	if(modpos==0){
		if(move==7||move==4||move==1){
			return false;
		}
	}
	if(modpos==9){
		if(move==9||move==6||move==3){
			return false;
		}
	}
	if((ppos>=90)&&(ppos<=99)){
		if(move==1||move==2||move==3){
			return false;
		}
	}
	if (ppos==5)return false;
	return true;
}
int rmove(int rpos){
	srand(time(NULL));
	int ran;
	ran=(rand() %9) +1;
	while(bound(rpos,ran)==false){
		ran =(rand() %9) +1;
		if (ran==5){
			ran =(rand() %9) +1;
		}
	}
	//printf("%d\n",ran);
		rpos=movementpos(ran,rpos);
	return rpos;
}
void gameplay(int* rpos,int* p1pos,int *p2pos,int* p3pos,int* p4pos,int * p1score, int* p2score, int* p3score, int* p4score, char * p1){
	int move;
	printf("%s enter movement direction: ", p1);
	scanf("%d",&move);
	while(bound(*p1pos,move)==false){
		printf("direction out of bounds %s in movement direction: ", p1);
		scanf("%d",&move);
	}
	//	getchar();
	//}
	*p1pos=movementpos(move,*p1pos);
	if(*p1pos==*rpos){
		*p1score+=50;
		*rpos = rand() % 100;
		while(*rpos==*p1pos||*rpos==*p2pos||*rpos==*p3pos||*rpos==*p4pos)*rpos = rand() % 100;
	}
	if(*p1pos==*p2pos){
		*p1score+=*p2score;
		*p2score=0;
		*p2pos = rand() % 100;
		while(*p2pos==*p1pos||*p2pos==*p3pos||*p2pos==*p4pos)*p2pos = rand() % 100;
	}
	if(*p1pos==*p3pos){
		*p1score+=*p3score;
		*p3score=0;
		*p3pos = rand() % 100;
		while(*p3pos==*p1pos||*p3pos==*p2pos||*p3pos==*p4pos)*p3pos = rand() % 100;
	}
	if(*p1pos==*p4pos){
		*p1score+=*p4score;
		*p4score=0;
		*p4pos = rand() % 100;
		while(*p1pos==*p4pos||*p2pos==*p4pos||*p3pos==*p4pos)*p4pos = rand() % 100;
	}
	return;
}
int main(){ 
	srand(time(NULL));
	int rpos = rand() % 100;
	int p1pos = rand() % 100;
	int p2pos = rand() % 100;
	int p3pos = rand() % 100;
	int p4pos = rand() % 100;
	int p1score = 0;
	int p2score = 0;
	int p3score = 0;
	int p4score = 0;
	char *p1 ="john";
	char *p2 ="sue";
	char *p3 ="alex";
	char *p4 ="nick";
	int move;
	int turn=0;
	char exit='n';
	int start=0;
	int temprpos;
	notaken(&rpos,&p1pos,&p2pos,&p3pos,&p4pos,start);
	start++;
	while(1){
		printf("%d:%d:%d:%d:%d:\n",p1pos,p2pos,p3pos,p4pos,rpos);
		//while(p1pos==p2pos||p1pos==p3pos||p1pos==p4pos)*p1pos = rand() % 100;
		//printf("do you want to exit,y/n:\n");
		//scanf("%c",&exit);
		turn=0;//p1 turn
		displayFeild(rpos,p1pos,p2pos,p3pos,p4pos,p1score,p2score,p3score,p4score,p1,p2,p3,p4);
		//displayscores(p1score,p2score,p3score,p4score,p1,p2,p3,p4);
		printmovement();
		gameplay(&rpos,& p1pos, &p2pos, &p3pos, &p4pos,  &p1score,  &p2score, &p3score, &p4score, p1);
		temprpos=rpos;
		rpos=rmove(temprpos);
		while(rpos==p1pos||rpos==p2pos||rpos==p3pos||rpos==p4pos){
			rpos=rmove(temprpos);
			//printf("%d\n",rpos);
		}
		//p2 turn
		displayFeild(rpos,p1pos,p2pos,p3pos,p4pos,p1score,p2score,p3score,p4score,p1,p2,p3,p4);
		printmovement();
		gameplay(&rpos,& p2pos, &p1pos, &p3pos, &p4pos,  &p2score,  &p1score, &p3score, &p4score, p2);
		temprpos=rpos;
		rpos=rmove(temprpos);
		while(rpos==p1pos||rpos==p2pos||rpos==p3pos||rpos==p4pos){
			rpos=rmove(temprpos);
		}
		//p3 turn
		displayFeild(rpos,p1pos,p2pos,p3pos,p4pos,p1score,p2score,p3score,p4score,p1,p2,p3,p4);
		printmovement();
		gameplay(&rpos,& p3pos, &p2pos, &p1pos, &p4pos,  &p3score,  &p2score, &p1score, &p4score, p3);
		temprpos=rpos;
		rpos=rmove(temprpos);
		while(rpos==p1pos||rpos==p2pos||rpos==p3pos||rpos==p4pos){
			rpos=rmove(temprpos);
		}
		//p4 turn
		displayFeild(rpos,p1pos,p2pos,p3pos,p4pos,p1score,p2score,p3score,p4score,p1,p2,p3,p4);
		printmovement();
		gameplay(&rpos,& p4pos, &p2pos, &p3pos, &p1pos,  &p4score,  &p2score, &p3score, &p1score, p4);
		temprpos=rpos;
		rpos=rmove(temprpos);
		while(rpos==p1pos||rpos==p2pos||rpos==p3pos||rpos==p4pos){
			rpos=rmove(temprpos);
		}
		
	}
	return 0;
}