#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void add();
void sell();
void modify();
void del();
void diss();
void disp();
void search();
struct node{
	char pname[20];
	char price[20];
	int quan;
	struct node *link;
};
struct node *head=NULL;
struct node *g=NULL;
void main()
{
	int ch;
	system("cls");
	do
	{
	printf("\n\t\t");
	printf(" ********* *ELECTRONIC STORE* *********\n");
	printf("\n\n\n\n\n\n\t\t\t");
	printf("1.Add Products\n\t\t\t2.Modify Products\n\t\t\t3.Delete Products\n\t\t\t4.Search Products\n\t\t\t5.Display Products\n\t\t\t6.Sell products\n\t\t\t7.Display sales\n\t\t\t8.Exit\n\t\t\t");
	printf("\n\n\tEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: add();
		break;
		case 2: modify();
		break;
		case 3: del();
		break;
		case 4: search();
		break;
		case 5: disp();
		break;
		case 6: sell();
		break;
		case 7: diss();
		break;
		case 8: exit(0);
		break;
		default:
		system("cls");
		printf("\nWrong Choice!!!\n");
		break;
	}
	printf("\n\nPress any key to go back to the menu\n");
	getch();
	system("cls");
	}while(1);
}
void add()
{
	struct node *temp;
	system("cls");
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the name of the product:  ");
	fflush(stdin);
	scanf("%[^\n]s",temp->pname);
	printf("\nEnter the price of the product: ");
	scanf("%s",temp->price);
	printf("\nEnter the number of products: ");
	scanf("%d",&temp->quan);
	printf("\nProduct added!!!\n");
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node *p;
		p=head;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
void modify()
{
	char edt[20];
	struct node *p;
	system("cls");
	p=head;
	if(p==NULL)
	{
		printf("\nNothing to modify!!!\n");
	}
	else
	{
		printf("\nEnter the product you want to edit: ");
		fflush(stdin);
		scanf("%[^\n]s",edt);
		while(strcmpi(edt,p->pname)!=0&&p->link!=NULL)
		{
			p=p->link;
		}
		if(strcmpi(edt,p->pname)==0)
		{
		printf("\nEnter the new name of the product:  ");
		fflush(stdin);
		scanf("%[^\n]s",p->pname);
		printf("\nEnter the price of the product: ");
		scanf("%s",p->price);
		printf("\nEnter the number of products: ");
		scanf("%d",&p->quan);
		printf("\nProduct modified!!!\n");
		}
		else
		{
			printf("\nProduct not found!!!\n");
		}
	}
}
void sell()
{
	char sel[20];
	int no;
	struct node *p,*q;
	struct node *tmp;
	system("cls");
	p=head;
	if(head==NULL)
	{
	printf("\nNothing to sell!!!\n");
	}
	else
	{
		printf("\nEnter the product you want to sell: ");
		fflush(stdin);
		scanf("%[^\n]s",sel);
		printf("\nNumber of products you want to sell: ");
		scanf("%d",&no);
		while(strcmpi(sel,p->pname)!=0&&p->link!=NULL)
		{
			p=p->link;
		}
		if(strcmpi(sel,p->pname)==0&&p->quan>=no)
		{
		     p->quan=p->quan-no;
		     printf("\nProduct sold!!!\n");
		    tmp=(struct node *)malloc(sizeof(struct node));
		    strcpy(tmp->pname,p->pname);
		    tmp->quan=no;
		    strcpy(tmp->price,p->price);
			tmp->link=NULL;
			if(g==NULL)
			{
				g=tmp;
			}
			else
			{
				q=g;
				while(q->link!=NULL)
				{
					q=q->link;
				}
				q->link=tmp;
			}
		}
		else
		{
			if(strcmpi(sel,p->pname)!=0)
			{
			printf("\nProduct not found!!!\n");
			}
			else
			{
			printf("\nProduct quantity not available!!!\n");
			}
		}
}
}
void del()
{
	struct node *p,*q;
	char del[20];
    system("cls");
	p=head;
	q=head->link;
	if(head==NULL)
	{
		printf("\nNothing to delete!!!\n");
	}
	else
	{
		printf("\nEnter the product you want to delete: ");
		fflush(stdin);
		scanf("%[^\n]s",del);
		if(strcmpi(del,p->pname)==0)
		{
			head=head->link;
			printf("\nProduct deleted!!!\n");
		}

	    else {
	while(strcmpi(del,q->pname)!=0&&q->link!=NULL)
	{
		p=p->link;
		q=q->link;
	}
	if(strcmpi(del,q->pname)==0)
	{
		p->link=q->link;
		free(q);
		printf("\nProduct deleted!!!\n");
	}
	else
	{
		printf("\nProduct not found!!!\n");
	}
	}
}
}
void search()
{
	struct node *p;
	char ser[20];
	system("cls");
	p=head;
	if(p==NULL)
	{
		printf("\nNothing to search!!!\n");
	}
	else
	{
		printf("\nEnter the product you want to search: ");
		fflush(stdin);
		scanf("%[^\n]s",ser);
		while(strcmpi(ser,p->pname)!=0&&p->link!=NULL)
		{
			p=p->link;
		}
		if(strcmpi(ser,p->pname)==0)
		{
		printf("\nName of product: %s\n",p->pname);
		printf("Price of product: %s\n",p->price);
		printf("Products available: %d\n",p->quan);
		}
		else
		{
			printf("\nProduct not found!!!\n");
		}
	}
}
void disp()
{
	struct node *p;
	int ch;
	system("cls");
	p=head;
	  if(p==NULL)
	  {
	  printf("\nNothing to display!!!\n");
	  }
	else
	{
	printf("\nProducts are:\n\n");
	while(p!=NULL)
	{
		printf("Name of product: %s\n",p->pname);
		printf("Price of product: %s\n",p->price);
		printf("Products available: %d\n",p->quan);
	printf("------------------------------------\n\n");
		p=p->link;
	}
	}
}
void diss()
{
	struct node *a;
	system("cls");
	a=g;
	   if(a==NULL)
	   {
		   printf("\nNothing to display!!!\n");
	   }
	   else
	   {

	   printf("\nProducts are:\n\n");
		   while(a!=NULL)
		   {
	      printf("Name of product: %s\n",a->pname);
		  printf("Price of product: %s\n",a->price);
		  printf("Products sold: %d\n",a->quan);
	      printf("------------------------------------\n\n");
		  a=a->link;
	       }
	    }
}


