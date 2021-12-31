#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
char flames(int len)
{
	system("color 5f");
	char z;
	int size=6;
	char flms[size]="FLAMES";
	int flc=len;
	int key,k=0,count=0;
	while(size>1)
	{
		key=flc%size;
		if(key==0)
		{
			flms[size-1]='0';
			key=0;
		}
		else
		flms[key-1]='0';
		char tmp[size-1]={};
		int i=key;
		while(1)
		{
			if(i==size)
			i=0;
			if(flms[i]=='0')
			--count;
			else
			tmp[k++]=flms[i];
			count++;
			if(count==size-1)
			break;
			i++;
		}
		for(int i=0;i<k;i++)
		{			
			flms[i]=tmp[i];
		}		
		size--;
		k=0;
		count=0;
		z=tmp[0];
	}
	return z;
}
int main()
{
	printf("##-->>Created by PlayerOne_Navin\n");
	int k=0,flag=0;
	char player1[30]={},player2[30]={},p1[30]={},p2[30]={};
	system("color 9");
	printf("Enter Name : ");
	gets(player1);
	fflush(stdin);
	printf("Enter another Name : ");
	gets(player2);
	for(int i=0;i<strlen(player1);i++)
	{
		if(player1[i]==' ')
		continue;
		else
		p1[k++]=toupper(player1[i]);
	}
	k=0;
	for(int i=0;i<strlen(player2);i++)
	{
		if(player2[i]==' ')
		continue;
		else
		p2[k++]=toupper(player2[i]);
	}
	for(int i=0;i<strlen(p1);i++)
	{
		for(int j=0;j<strlen(p2);j++)
		{
			if(p1[i]==p2[j])
			{
				p1[i]='0';
				p2[j]='0';
				break;
			}
		}
	}
	for(int i=0;i<strlen(p1);i++)
	if(p1[i]!='0')
	flag++;
	for(int i=0;i<strlen(p2);i++)
	if(p2[i]!='0')
	flag++;
	switch(flames(flag))
	{
		case 'F':
			printf("%s is friend to %s",player1,player2);
			break;
		case 'L':
			printf("%s is in love with %s",player1,player2);
			break;
		case 'A':
			printf("%s is in Affection with %s",player1,player2);
			break;
		case 'M':
			printf("%s is gonna marry %s soon...",player1,player2);
			break;
		case 'E':
			printf("%s is Enemy of %s",player1,player2);
			break;
		case 'S':
			printf("%s is brother/sister to %s",player1,player2);
			break;
		case '0':
			printf("Something went wrong while calculating ;)");
	}
	return 0;
}
