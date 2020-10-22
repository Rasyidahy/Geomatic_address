#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char address[50];
 };
 
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 5f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{	
	system("cls");
	printf("\t\t**********WELCOME BACK*************");
	
	printf("\n\n\t\t\t  MENU\t\t\n\n");
	printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search \t6.Delete");
	
	switch(getch())
	{
	    case '1':
	    	addrecord();
	    break;
	   	case '2': 
		   listrecord();
	    break;
	    case '3': 
			exit(0);
	    break;
	    case '4': 
			modifyrecord();
	    break;
	    case '5': 
			searchrecord();
	    break;
	    case '6': 
			deleterecord();	
	    break;
	    
	    default:
	                system("cls");
	                printf("\nEnter 1 to 6 only");
	                printf("\n Enter any key");
	                
	                getch();
	
		menu();
	}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\n Enter address: ");
        got(p.address);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nrecord saved");

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
	f=fopen("project","rb");
	if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
	while(fread(&p,sizeof(p),1,f)==1)
{
    printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nAddress=%s",p.address);

	getch();
	system("cls");
}
fclose(f);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
	FILE *f;
	char address[100];
	
	f=fopen("project","rb");
	if(f==NULL)
	
	{
	    printf("\n error in opening\a\a\a\a");
	    exit(1);
	
	}
	printf("\nEnter address of person to search\n");
	got(address);
	while(fread(&p,sizeof(p),1,f)==1)
	
	{		
    	if(strcmp(p.address,address)==0)
	    {
	        printf("\n\tDetail Information About %s",address);
	        printf("\nAddress:%s",p.address);
	    }
        else
        printf("file not found");

	}
	
 fclose(f);
  	printf("\n Enter any key");

	getch();
    system("cls");
	menu();
}

void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char address[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("Enter address:");
		got(address);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.address,address)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.address,address)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  address[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter ADDRESS TO MODIFY:\n");
            got(address);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(address,p.address)==0)
                {

                    printf("\n Enter address:");
                    got(s.address);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;

                }
                fflush(stdin);

            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}
void got(char *address)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(address+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(address+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(address+i)='\0';
}
