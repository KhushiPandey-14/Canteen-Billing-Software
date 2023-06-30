#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define len 100
char cqueue[len][100];
int queue_front=-1,queue_rear=-1;

struct place_order
{
    char name_of_customer[50];
    char invoice_date[50];
    char time[50];
    int num_of_items;
    
    struct items
	{
    char canteen_item[50];
    int quantity_of_item;
    float price_of_item;
    }product[50];

}ord1,ord2;

void addproduct(char cqueue[len][100],int *queue_rear){
char food[100];
if(*queue_rear==len-1)
printf("Queue is full!! Overflow!\n");
else
{
	if(queue_front==-1)
	queue_front=0;
	printf("Enter the Food:");
	scanf("%s",&food);
	*queue_rear=*queue_rear+1;
	strcpy(cqueue[*queue_rear],food);
}
printf("Successfully added!!\n");
}

void showproduct(char cqueue[len][100],int *queue_rear,int *queue_front){
	int j;
	if(*queue_rear==-1 && *queue_front==-1)
	{
		printf("Opps!! Product is unavailable\n");
		return;
	}
	else
	{
		printf("List of menu available:\n");
		for(j=*queue_front;j<=*queue_rear;j++)
		printf("%s\n",cqueue[j]);
	}
	}

//Modules to generate the bill of the customer
void BillHeader(char customer_name[50],char invoice_date[30],char time[40]){
        printf("\n\n\t  ******************");
        printf("\n\t   DELICIA CANTEEN");
        printf("\n\t  *****************");
        printf("\nDATE: %s",invoice_date);
        printf("\nTIME: %s",time);
        printf("\nCUSTOMER NAME: %s",customer_name);
        printf("\n__________________________________________\n");
        printf("ITEMS\t\tQTY\t\tTOTAL\n");
        printf("_________________________________________\n\n");
}

void BillBody(char product[30],int quantity, float cost){
    printf("%s\t\t%d\t\t%.1f\t\t\n",product,quantity,(quantity*cost)); 
}

void BillFooter(float amount){
    float discount,net_amt,cgst_tax,total;
    discount = 0.2*amount; //20% Discount
    net_amt=amount-discount;
    cgst_tax=(0.06)*net_amt;   //6% GST
	total=net_amt + cgst_tax + cgst_tax;//net_amt + cgst_tax + sgst_tax
	printf("\n_______________________________________\n");
    printf("TOTAL\t\t\t\t%.1f",amount);
    printf("\nDISCOUNT @20% %s\t\t\t%.1f",discount);
    printf("\n\t\t\t\t________\nNET TOTAL\t\t\t%.1f",net_amt);
    printf("\nCGST @6%s\t\t\t%.1f","%",cgst_tax);
    printf("\nSGST @6%s\t\t\t%.1f","%",cgst_tax);
    printf("\n_________________________________________");
    printf("\nTotal Amount\t\t\t%.1f",total);
   printf("\n__________________________________________\n");
}

//main function
int main(){
    int choice1,choice2,choice3,num,j,login=0;
    char save_invoice = 'y',flag1 = 'y',flag2 = 'y',flag = 'y';
    char search_name[50],username[100],passwd[20];
    float amount = 0,total,total2;
	int available = 0; 
    FILE *fptr;
    FILE *fp1;
    
    while(flag1 == 'y')
    {
    system("cls");
    printf("\n*************************************************");
    printf("\n         WELCOME TO DELICIA CANTEEN               \n"); 
	printf("**************************************************"); 
    printf("\n\nSelect your prefered operation");
    printf("\n1-Login");
    printf("\n2-Admin mode");
    printf("\n3-Menu display");
    printf("\n4-Buyer Mode(Place Order)");
 	printf("\n5-Exit");
 	printf("\n\nEnter your choice:\t");
    scanf("%d",&choice1);
    switch(choice1){
    case 1:
    	printf("Enter Username: ");
    	scanf("%s",username);
    	printf("Enter Password: ");
    	scanf("%s",passwd);
    	if(!strcmp(username,"kkk") && !strcmp(passwd,"ppp"))
    	{
    	printf("Successfully logged in!!");
    	login=1;
        }
    	else
    	printf("Invalid login details!!!");
    	break;
    	
    //Admin mode	
    case 2:
    if(login==1)
	{
    system("cls");	
	printf("\nWELCOME TO ADMINISTARTOR MODE\n");
	printf("-------------------------------");
	while(flag2 == 'y'){
	printf("\n\nSelect your prefered option\n");
    printf("\n1.Add product details");
    printf("\n2.Show all the product details");
    printf("\n3.Exit");
    printf("\n\nEnter your choice:\t");
    scanf("%d",&choice2);
    switch(choice2){
        case 1:
        	addproduct(cqueue,&queue_rear);
        	break;
        case 2:
        	showproduct(cqueue,&queue_rear,&queue_front);
        	break;
        case 3:
        	printf("Thank you! Byee:))");
        	exit(0);
        	break;
        default:
		printf("\nInvalid option!");   
    }

    printf("\nWant to execute any other operation in admin mode??[y/n]");
    scanf("%s",&flag2);
}
}
else
	printf("Login to enter the admin mode!");
    break;
    //End of admin mode
    
    //Menu display
    case 3:
    if(login==1)
    {
	initwindow(800,600,"DELICIA CANTEEN");
	cleardevice();
	readimagefile("cafe.jpg",0,0,800,600);
	getch();
	closegraph();
   }
    else
    printf("Login to view the menu!");
	break;
    //End of Menu display
    
	//Buyer mode 	
	case 4: 
	if(login==1)
    { 
    system("cls");
	printf("\n\tWELCOME TO BUYER MODE...PLACE THE ORDER!!\n");
	printf("\t--------------------------------------------\n");	
    while(flag == 'y'){
    printf("   ***********DELICIA CANTEEN***********\n\n");
    printf("Select your prefered option\n");
    printf("\n1.To Generate Bill");
    printf("\n2.Display all the Invoices");
    printf("\n3.Search for a Customer's Invoice");
    printf("\n4.Exit\n\n");
    printf("Enter your choice:\t");
    scanf("%d",&choice2);
    fgetc(stdin);
    switch(choice2){
        case 1:
        system("cls");
        printf("\nEnter the customer's name:");
        fgets(ord1.name_of_customer,50,stdin);
        ord1.name_of_customer[strlen(ord1.name_of_customer)-1] = 0;  //to remove the \n from the end of string
        strcpy(ord1.invoice_date,__DATE__);
        strcpy(ord1.time,__TIME__);
        printf("\nEnter the number of items:");
        scanf("\t%d",&num);
        ord1.num_of_items = num;
        for(j=0;j<num;j++){
            fgetc(stdin);
            printf("\n\nEnter the item %d:\t",j+1);
            fgets(ord1.product[j].canteen_item,50,stdin);
            ord1.product[j].canteen_item[strlen(ord1.product[j].canteen_item)-1] = 0;
            printf("Enter the quantity:\t");
            scanf("%d",&ord1.product[j].quantity_of_item);
            printf("Enter the unit cost:\t");
            scanf("%f",&ord1.product[j].price_of_item);
            amount += ord1.product[j].quantity_of_item * ord1.product[j].price_of_item;
        }

        BillHeader(ord1.name_of_customer,ord1.invoice_date,ord1.time);
        for(j=0;j<ord1.num_of_items;j++){
            BillBody(ord1.product[j].canteen_item,ord1.product[j].quantity_of_item,ord1.product[j].price_of_item);
        }
        BillFooter(amount);

        printf("\nSAVE the invoice??[y/n]:\t");
        scanf("%s",&save_invoice);
        if(save_invoice == 'y')
		{
            fptr = fopen("CanteenBilling.txt","ab+");
            fwrite(&ord1,sizeof(struct place_order),1,fptr);
            if(fwrite == 0)
            printf("\nSorry! File cannot be saved! Error!");
            else
            printf("\nFile is saved successfully!!");
            fclose(fptr);
        }
        break;

        case 2:
        system("cls");
        fptr = fopen("CanteenBilling.txt","rb");
        printf("\n  *****THE PREVIOUS INVOICES*****\n");
        printf("-------------------------------------");
        while(fread(&ord2,sizeof(struct place_order),1,fptr))
		{
			total=0;
            BillHeader(ord2.name_of_customer,ord2.invoice_date,ord2.time);
            for(j=0;j<ord2.num_of_items;j++){
                BillBody(ord2.product[j].canteen_item,ord2.product[j].quantity_of_item,ord2.product[j].price_of_item);
                total+=ord2.product[j].quantity_of_item * ord2.product[j].price_of_item;
            }
            BillFooter(total);
        }
        fclose(fptr);
        break;

        case 3:
        printf("Enter the customer's name to be searched:\t");
        fgets(search_name,50,stdin);
        search_name[strlen(search_name)-1] = 0;
        system("cls");
        fptr = fopen("CanteenBilling.txt","rb+");
        printf("-------Invoice of %s-------",search_name);
        printf("\n------------------------------");
        while(fread(&ord2,sizeof(struct place_order),1,fptr)){
            total2 = 0;
            if(!strcmp(ord2.name_of_customer,search_name)){
            BillHeader(ord2.name_of_customer,ord2.invoice_date,ord2.time);
            for(j=0;j<ord2.num_of_items;j++){
                BillBody(ord2.product[j].canteen_item,ord2.product[j].quantity_of_item,ord2.product[j].price_of_item);
                total2+=ord2.product[j].quantity_of_item * ord2.product[j].price_of_item;
            }
            BillFooter(total2);
            available = 1;
            }
        }
        if(!available){
            printf("\nSorry!! Invoice of %s is not available!!",search_name);
        }
        fclose(fptr);
        break;

    case 4:
    printf("\n\t    Thank you for visiting us!!\n\n");	
    printf("\t\t Have a great day! Byeee:)\n\n");
    exit(0);
    break;
		
    default:
    printf("Oopps!! Invalid choice!");
    break;
    }

    printf("\nWant to execute any other operation in buyer mode??[y/n]:\t");
    scanf("%s",&flag);
}
}
else
{
	printf("Login to enter the buyer mode!");
}
break;
return 1;
//End of buyer mode


    case 5:
    printf("\n\t Thank you for visiting us!! :)");
	exit(0);
		
	default:
	printf("Opps!! Inavild choice!");  
}

printf("\nWant to execute any other operations from main menu?[y/n]:\t");
    scanf("%s",&flag1);
}
    return 0;
}