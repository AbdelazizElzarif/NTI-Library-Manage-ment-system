#include<stdio.h>
#include<stdlib.h>
#include"lib.h"
static int stat,index;
static int book_count=0,G_F=1;
Library books[BOOK_MAX]={0};
void Library_runaable(void)
{
	
		scanf("%d",&stat);
		switch(stat)
		{
			case 1:
			
				printf("please enter the roof of library\n");
				scanf("%d",&index);
				if(book_add(&books[index]))
		        {
			        printf("\nsucess addiation\n");
		        }
	        	else
	        	{
		         	printf("\nfailed addiation\n");
		        }
				
				break;
			
			case 2:
			if(BORROW_BOOK())
		    {
			     printf("\nborrow book done\n");
		    }
			else
		    {
			     printf("\nbook is not avalibale to borrow\n");
		    } 
			break;
			case 3:
			if(Buy_BooK())
			{
				 printf("buy books done\n");
			}
			else
			{
				 printf("you dont have this book please add this book\n");
			}
			break;
			case 4:
			if(DELET_BOOK())
		    {
			     printf("\nDELET_BOOK done\n");
		    }
		    else
		    {
			    printf("\n book is not avalibale to delet\n");
		    }
			break;
			case 5:
			print_library();
			break;
			case 6:
			show_menu();
			break;
			case 7:
			exit2();
			break;
		
			
			
			
		}
		

}	

char book_add(Library* book)
{
	char S=0;
	char i=0;
	char s_add=1;
	char s_embty=0;
	char flag_add=1;
	char str[MAX_TITLE];	   
	printf("please enter the name of the book\n");
	string_scan(str,MAX_TITLE);
	
	
	       for(i=0;i<BOOK_MAX;i++)
		   {
			    s_embty=string_same(str,books[i].BOOK_TITLE);
				if(s_embty==1)
				{
					break;
				}
				
		   }
		   if(s_embty==1)
				{
					
					s_add=0;
					flag_add=0;
					books[i].NUMPER_COPIES++;
				    book_count++;
					S=1;
					
					
					
				}
				
		  
	
	if(s_add==1&&(book->puplication_year==0))
	{
		string_copy(book->BOOK_TITLE,str);
		S=1;
		book_count++;
		
		printf("please enter the author name of the book\n");
	    string_scan(book->AUTHOR_NAME,MAX_AUTHOR);
	    printf("enter the puplication year\n");
	    scanf("%d",&(book->puplication_year));
	    book->NUMPER_COPIES++;
	   printf("enter the price of book\n");
	   scanf("%f",&(book->PRICE));
	   book_avalibale(book->STATUS);
	   
	}
	else if(flag_add==1)
	{
		
	   if(book_count==BOOK_MAX)
	   {
		   printf("the library is full\n");
		   
	   }
	   else
	   {
		   
		   char s_embty=0;
		   for(i=0;i<BOOK_MAX;i++)
		   {
			    s_embty=string_same("notalibale",books[i].STATUS);
				if(s_embty==1)
				{
					printf("please add book in %d \n",i);
					break;
				}
		   }
		   
		  
	   }
	   
	}
	else
	{
		
	}
		
	return S ;
}



void exit2(void)
{
	G_F=0;
}


char Buy_BooK(void)
{
	int i;
	char s=0,f=0;
	char str[MAX_AUTHOR];
	int num;
	printf("please enter the name of book\n");
	string_scan(str,MAX_AUTHOR);
	printf("please enter the nums of book that you need to buy\n");
	scanf("%d",&num);
	for(i=0;i<BOOK_MAX&&f==0;i++)
		   {
			    s=string_same(str,books[i].BOOK_TITLE);
				if(s==1)
				{
	
					books[i].NUMPER_COPIES+=num;
					book_count+=num;
					
					f=1;
				}
		   }
		   
		   return f;
}


char DELET_BOOK(void)
{
	int i;
	char s=0,f=0;
	char str[MAX_AUTHOR];
	printf("name of delet book\n");
	string_scan(str,MAX_AUTHOR);
	for(i=0;i<BOOK_MAX&&f==0;i++)
		   {
			    s=string_same(str,books[i].BOOK_TITLE);
				if(s==1)
				{
					books[i].BOOK_TITLE[0]=0;
					books[i].puplication_year=0;
					book_count-=books[i].NUMPER_COPIES;
					f=1;
				}
		   }
		   
		   return f;
}


char BORROW_BOOK(void)
{
	int i;
	char s=0,f=0;
	char str[MAX_AUTHOR];
	printf("please enter the name of book that you need to borrow\n");
	string_scan(str,MAX_AUTHOR);
	for(i=0;i<BOOK_MAX&&f==0;i++)
		   {
			    s=string_same(str,books[i].BOOK_TITLE);
				if(s==1&&books[i].NUMPER_COPIES>0)
				{
					books[i].NUMPER_COPIES--;
					book_count--;
					f=1;
				}
				else if(books[i].NUMPER_COPIES==0)
				{
					book_notavalibale(books[i].STATUS);
				}
		   }
		   
		   return f;
}


void show_menu(void)
{
	printf("to add book enter      1\n");
	printf("to borrow book enter   2\n");
	printf("to buy book enter      3\n");
	printf("to delet book enter    4\n");
	printf("to print library enter 5\n");
	printf("to show menu enter     6\n");
	printf("to exit enter          7\n");
}


char string_same(char*str1,char* str2)
{
	int i;
	char c1;
	char c2;
	for(i=0;str1[i]||str2[i];i++)
	{
		c1=str1[i];
		c2=str2[i];
		if(c1>='A'&&c1<='Z')
		{
			c1=c1-'A'+'a';
		}
		if(c2>='A'&&c2<='Z')
		{
			c2=c2-'A'+'a';
		}
		if(c1!=c2)
		{
			return 0;
		}
	}
	return 1;
}
void string_scan(char* str,char size)
{
	int i;
	fflush(stdin);
	scanf("%c",&str[0]);
	for(i=0;((str[i]!='\n')&&(i<size));)
	{
		i++;
		scanf("%c",&str[i]);
	}
	str[i]=0;
}
void book_avalibale(char*str1)
{
	char str2[20]="avalibale";
	int i=0;
	for(i=0;str2[i];i++)
	{
		str1[i]=str2[i];
	}
	str1[i]=0;
}

void book_notavalibale(char*str1)
{
	char str2[20]="notavalibale";
	int i=0;
	for(i=0;str2[i];i++)
	{
		str1[i]=str2[i];
	}
	str1[i]=0;
}


void print_library(void)
{
	char i;
	for(i=0;i<BOOK_MAX;i++)
	{
		if(books[i].puplication_year!=0)
		{
			printf("book title is:");
		    string_print(books[i].BOOK_TITLE);
			printf("AUTHOR_NAME is:");
		    string_print(books[i].AUTHOR_NAME);
			printf("PUPLICATION YEAR is:");
			printf("%d\n",books[i].puplication_year);
			printf("NUMPER COPIES is:");
			printf("%d\n",books[i].NUMPER_COPIES);
			printf("PRICE is:");
			printf("%f\n",books[i].PRICE);
			printf("BOOK STATUS is:");
		    string_print(books[i].STATUS);
			printf("numper of books is:");
		    printf("%d\n",book_count);
		    
			
		}
		
		
	}
}
void string_print(char* str)
{
	int i;
	for(i=0;str[i];i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}
void string_copy(char*str1,char*str2)
{
	int i;
	for(i=0;str2[i];i++)
	{
		str1[i]=str2[i];
	}
	str1[i]=0;
}
int getter_gf(void)
{
	return G_F;
}
void Library_init(void)
{
	printf("to add book enter      1\n");
	printf("to borrow book enter   2\n");
	printf("to buy book enter      3\n");
	printf("to delet book enter    4\n");
	printf("to print library enter 5\n");
	printf("to show menu enter     6\n");
	printf("to exit enter          7\n");
}