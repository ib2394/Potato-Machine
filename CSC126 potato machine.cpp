/*
GROUP MEMBERS :
1. AIDA SYAZWANI BINTI SAMANI
2. IBTISAM BINTI ASRUL HAFIZ
3. SITI HAZIRAH BINTI MAZLAN
4. NUR FARAH AISYAH BINTI SHARUDIN

GROUP : CS1101B

DATE : 27 JANUARY 2023

PROJECT NAME : POTATO MACHINE
*/
#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
using namespace std;
void greeting();
void guest();
void makeOrder(double&, int&);
void mainMenu();
void admin();
void adminPage();
void cash(double);
void creditCard(double);
void eWallet(double);
void paypal(double);
void listCode();
void confirmationPayment(double, int);
void payment(double, int);
void printStock();
void printTotSale();
void logout();
double totalSales=0;
int countCustomer=0;
int stock=100; //stock for potato
int main(){
	greeting();
	mainMenu();
    return 0;
}
void greeting(){
	cout<<"\tWELCOME TO POTATO MACHINE"<<endl<<endl;
	system("PAUSE");
}
void mainMenu(){
	char choose;
	system("cls");
	cout<<"+----------------------------------------+"<<endl;
	cout<<"|              MAIN MENU                 |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
	cout<<"|        1.  Administrator   [A]         |"<<endl;
	cout<<"|        2.  Customer        [C]         |"<<endl;
	cout<<"|        3.  CLOSE Program   [X]         |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
		do{
			cout<<" Choose Login As  : ";
			cin>>choose;
				
			if (toupper(choose)=='A'||choose=='1'){
				admin();
			}
			else if(toupper(choose)=='C'||choose=='2'){
				cout<<"+----------------------------------------+"<<endl;
				sleep(2);
				if(stock<1){
					system("cls");					
					cout<<"Sorry, we ran out of potato :( Please come again later."<<endl;
					system("PAUSE");
					system("cls");
					mainMenu();
				}
				else
					guest();
			}
			else if(toupper(choose)=='X'||choose=='3'){
				logout();
				exit(0);
			}
		}while(toupper(choose)!='A'&&choose!='1'&&toupper(choose)!='C'&&choose!='2'&&toupper(choose)!='X'&&choose!='3');
}
void admin(){
	char adminName[50],password[50]= "12345", passwordAdmin[50];
	cin.ignore(1024,'\n');
	
	for(int i=0;i<3;i++){ //3 attempts to log in to the admin page
		cout<<" Enter your name  : ";
		cin.getline(adminName,50);
		cout<<" Enter password   : ";
		cin.getline(passwordAdmin,50);
		if(strcmp(password,passwordAdmin)==0){
			sleep(2);
			system("cls");
			cout<<"\n";
			cout<<"   ***** Welcome admin "<<adminName<< "! *****"<<endl;
			cout<<"\n";
			adminPage();
		}
		else{
			cout<<"\t+---------------+"<<endl;
			cout<<"\t| Access denied |"<<endl;
			cout<<"\t+---------------+"<<endl;		
		}
	}
	cout<<" FAILED TO LOGIN AS ADMIN.\n THE PROGRAM WILL TERMINATED."<<endl;
	sleep(3);
	logout();
}
void adminPage(){
	char proceed;
	cout<<"+-----------------------------------+"<<endl;
	cout<<"|       Welcome to Admin Page       |"<<endl;
	cout<<"+-----------------------------------+"<<endl;
	cout<<"|   1  | Total Stock of Potato Left |"<<endl;
	cout<<"+-----------------------------------+"<<endl;
	cout<<"|   2  | Total Sale                 |"<<endl;
	cout<<"+-----------------------------------+"<<endl;
	cout<<"|   3  | Main Menu                  |"<<endl;
	cout<<"+-----------------------------------+"<<endl;
	do{
		cout<<"Please enter the code to continue: ";
		cin>> proceed;
		if (proceed=='1')
			printStock();
		else if(proceed=='2')
			printTotSale(); 
		else if(proceed=='3')
			mainMenu();
		else 
			cout<<"INVALID CODE"<<endl<<endl;
	}while(proceed!='1'&&proceed!='2'&&proceed!='3');
}
void guest(){
	cin.ignore(1024,'\n');
	int qty=0;
    double totalPrice=0;
    char order, anotherOrder, name[20];
    
	system("cls");
	cout<<"+----------------------------------+"<<endl;
	cout<<"|       WELCOME TO GUEST PAGE      |"<<endl;
	cout<<"+----------------------------------+"<<endl;
	cout<<"Please enter your name: " ;
	cin.getline(name,20);
	cout<<"+----------------------------------+"<<endl;
	cout<<"     Hi " <<name<<"   ^-^\t\t   "<<endl;
	cout<<"     Welcome to Potato Machine    "<<endl;
	cout<<"+----------------------------------+"<<endl;
	sleep(2);
	  
	do{	  
		system("cls");
		cout<<"+---------------------------+"<<endl;
		cout<<"\tHi "<< name <<"!"<<endl;
		cout<<"+---------------------------+"<<endl;
		do{
			cout<<"Do you want to order?(Y/N): "; //to confirm in making an order
		    cin>> order;
		}while(toupper(order)!='Y' && toupper(order)!='N');  
		 system("cls");
		
		if(toupper(order)=='Y'){
			qty++; //to count the total of potato purchased
			makeOrder(totalPrice, qty);
			cout<<"BUY 3 FREE 1! Add another to get a special potato."<<endl;
			cout<<"Press [Y] to add another order: ";
			cin>>anotherOrder;  
		}
		else
			break;
	}while(toupper(anotherOrder)=='Y');
		
	if(toupper(order)=='N'){
		if(qty<1) //to avoid counting customer when customer doesn't wants to order when they first visited customer page
			mainMenu();
		else //when they make >1 order but doesn't wants to order because pressed the wrong code when adding another order.
	    	payment(totalPrice, qty); 
	}
	
	confirmationPayment(totalPrice, qty);
}
//for making an order
void makeOrder(double&totalPrice, int&qty){
	int sizePrice,toppingPrice, price, size[2]={5,7}, topping[5]={1,3,1,4,0};
	char sauceCode, toppingCode, flavor, potatoSize, potatoType;
	
	//potato type
    do{
        cout<<"\n+----+---------------------------+"<<endl;
        cout<<"|CODE|        POTATO TYPE        |"<<endl;
        cout<<"+----+---------------------------+"<<endl;
        cout<<"|[1] | MASHED POTATO             |"<<endl;
        cout<<"|[2] | SPRING POTATO             |"<<endl;
        cout<<"|[3] | CHIPS                     |"<<endl;
        cout<<"|[4] | FRENCH FRIES              |"<<endl;
        cout<<"|[5] | WEDGES                    |"<<endl;
        cout<<"+----+---------------------------+"<<endl;
        cout<<"Choose your potato type: ";
        cin>> potatoType;
    }while(toupper(potatoType)!='1' && toupper(potatoType)!='2' && toupper(potatoType)!='3' && toupper(potatoType)!='4' && toupper(potatoType)!='5');

 	//potato size
    do{
        cout<<"\n+----+-----------------------+"<<endl;
        cout<<"|CODE|      POTATO SIZE      |"<<endl;
        cout<<"+----+-----------------------+"<<endl;
        cout<<"|[1] | MEDIUM    (RM5)       |"<<endl;
    	cout<<"|[2] | LARGE     (RM7)       |"<<endl;
        cout<<"+----+-----------------------+"<<endl;
        cout<<"Choose size: ";
        cin>> potatoSize;
    }while(toupper(potatoSize)!='1' && toupper(potatoSize)!='2');
    if(toupper(potatoSize)=='1')
         sizePrice=size[0];
    else if(toupper(potatoSize)=='2')
         sizePrice=size[1];
             
    //flavor
    do{
        cout<<"\n+----+-----------------------+"<<endl;
        cout<<"|CODE|     POTATO FLAVOR     |"<<endl;
        cout<<"+----+-----------------------+"<<endl;
        cout<<"|[1] | ORIGINAL              |"<<endl;
        cout<<"|[2] | SPICY                 |"<<endl;
        cout<<"|[3] | HOT & SPICY           |"<<endl;
        cout<<"+----+-----------------------+"<<endl;
        cout<<"Choose your flavor: ";
        cin>> flavor;     
    }while(flavor!='1' && flavor!='2' && flavor!='3');
   	
    //topping
    do{
        cout<<"\n+----+-----------------------+"<<endl;
        cout<<"|CODE|     TOPPING           |"<<endl;
        cout<<"+----+-----------------------+"<<endl;
        cout<<"|[1] | CHILI FLAKES  (RM1)   |"<<endl;
        cout<<"|[2] | CHICKEN SLICE (RM3)   |"<<endl;
        cout<<"|[3] | BLACK PAPER   (RM1)   |"<<endl;
        cout<<"|[4] | BEEF BACON    (RM4)   |"<<endl;
        cout<<"|[5] | NONE                  |"<<endl;
        cout<<"+----+-----------------------+"<<endl;
        cout<<"Choose your topping: "; 
        cin>> toppingCode; 
    }while(toppingCode!='1' && toppingCode!='2' && toppingCode!='3' && toppingCode!='4' && toppingCode!='5');
    if(toppingCode=='1')
    	toppingPrice=topping[0];
    else if(toppingCode=='2')
    	toppingPrice=topping[1];
    else if(toppingCode=='3')
     toppingPrice=topping[2];
    else if(toppingCode=='4')
    	toppingPrice=topping[3];
    else if(toppingCode=='5')
    	toppingPrice=topping[4];
     
  	//sauce 
    do{
	    cout<<"\n+----+---------------------+"<<endl;
	    cout<<"|CODE|     SAUCE (FREE)    |"<<endl;
	    cout<<"+----+---------------------+"<<endl;
	    cout<<"|[1] | CHILI               |"<<endl;
	    cout<<"|[2] | TOMATO              |"<<endl;
		cout<<"|[3] | MAYONNAISE          |"<<endl;
	    cout<<"|[4] | CHEESE              |"<<endl;
	    cout<<"|[5] | THOUSAND ISLAND     |"<<endl;
	    cout<<"|[6] | NONE                |"<<endl;
	    cout<<"+----+---------------------+"<<endl;
	    cout<<"Choose your sauce: ";
	    cin>> sauceCode;
	}while(sauceCode!='1' && sauceCode!='2' && sauceCode!='3' && sauceCode!='4' && sauceCode!='5' && sauceCode!='6'); 	   
    
	price = sizePrice + toppingPrice;
	totalPrice += price;
	system("cls"); 	
	
	//to display an order that has been made
	listCode();
	cout<<"\nYour order: "<<endl;
	cout<<"+-------------------------+"<<endl;
	cout<<"|          |     CODE     |"<<endl;
	cout<<"+----------+--------------+"<<endl;
	cout<<"|TYPE      |"<<setw(6)<< potatoType <<setw(9)<<"|"<<endl;
	cout<<"+----------+--------------+"<<endl;
	cout<<"|SIZE      |"<<setw(6)<< potatoSize <<setw(9)<<"|"<<endl;
	cout<<"+----------+--------------+"<<endl;
	cout<<"|FLAVOR    |"<<setw(6)<< flavor <<setw(9)<<"|"<<endl;
	cout<<"+----------+--------------+"<<endl;
	cout<<"|TOPPING   |"<<setw(6)<< toppingCode <<setw(9)<<"|"<<endl;
	cout<<"+----------+--------------+"<<endl;
	cout<<"|SAUCE     |"<<setw(6)<< sauceCode <<setw(9)<<"|"<<endl;
	cout<<"+----------+--------------+"<<endl<<endl;
	cout<<"+------------------------------+-----------+"<<endl;
	cout<<"| Quantity of potato purchased |"<<setw(6)<<qty<<setw(6)<<"|"<<endl;   
	cout<<"|------------------------------+-----------+"<<endl;
	cout<<"| Total Purchase               |"<<setw(4)<<" RM "<<totalPrice<<setw(6)<<"|"<<endl;
	cout<<"+------------------------------+-----------+"<<endl<<endl;
   
   	//buy3free1
	if(qty==3){
		cout<<"+---------------------------+"<<endl;
		cout<<"| You got 1 special potato! |"<<endl;
		cout<<"+---------------------------+"<<endl;
	}
	
	//when customer is making an order but the machine has ran out of stock
	if(qty==stock){
		cout<<"\n";
		cout<<"+----------------------+"<<endl;
		cout<<"| We ran out of stock! |"<<endl;
		cout<<"+----------------------+"<<endl;
		confirmationPayment(totalPrice, qty);
	}
}
//to avoid careless mistake when pressing code
void confirmationPayment(double totalPrice, int qty){
	char proceed, cancel;
	
	cout<<"\nDo you want to proceed to payment? [P-Payment]: "; 
	cin>> proceed;
	if(toupper(proceed)=='P')
		payment(totalPrice, qty);
	else{ 
		system("cls");
		cout<<"\nAre you sure you want to cancel all order? [Y-Yes]: ";
		cin>>cancel;
		if(toupper(cancel)=='Y'){
			system("cls");
			mainMenu();		
		}
		else 
			payment(totalPrice, qty);
	}
}
//methods of payment
void payment(double totalPrice, int qty){
	char paymentType;
	countCustomer++;
	if(qty>=3)
		stock--; //the free potato is included in counting the total stock
	stock=stock-qty;
    do{
		system("cls");
		cout<<"\tPAYMENT"<<endl<<endl;
	    cout<<"+----------------------------+"<<endl;
	    cout<<"| PAYMENT METHOD  | DISCOUNT |"<<endl;
	    cout<<"+----------------------------+"<<endl;
	    cout<<"|[1] CASH         |    -     |"<<endl;
	    cout<<"+----------------------------+"<<endl;
	    cout<<"|[2] PAYPAL       |    2%    |"<<endl;
	    cout<<"+----------------------------+"<<endl;
	    cout<<"|[3] E-WALLET     |    3%    |"<<endl;
	    cout<<"+----------------------------+"<<endl;
	    cout<<"|[4] CREDIT CARD  |    5%    |"<<endl;
	    cout<<"+----------------------------+"<<endl;
		cout<<"Select your payment method: ";
		cin>> paymentType;
	}while(paymentType!='1'&&paymentType!='2'&&paymentType!='3'&&paymentType!='4');
	if (paymentType == '1')
		cash(totalPrice);
	else if (paymentType == '2')
		paypal(totalPrice);
	else if (paymentType == '3')
		eWallet(totalPrice);
	else if (paymentType == '4')
		creditCard(totalPrice);
	else 
		cout<<"Invalid input. "<<endl;
	
}
void cash(double totalPrice) {
	system("cls");
	double pay;
	cout<<"You choose to pay in CASH."<<endl<<endl;
	cout<<"\t------------------------------Receipt------------------------------"<<endl;
	cout<<"\t\t\tSubtotal           :RM " <<totalPrice<<endl;
	cout<<"\t\t\tAmount Paid        :RM ";
	cin>>pay;
	cout<<"\t\t\tBalance            :RM " <<(pay-totalPrice)<<endl;
	cout<<"\t-------------------------------------------------------------------"<<endl;
	cout<<"\nThank you for using Potato Machine." <<endl;
	
	totalSales+=totalPrice; 
	system("PAUSE");
	system("cls");
	mainMenu();
}
void creditCard(double totalPrice) {
	system("cls");
	double discount = 0.05;
	cout<<"You choose to pay using CREDIT CARD."<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Total           : RM "<<totalPrice<<endl;
	cout<<"Amount Due(-5%) : RM " <<totalPrice-(totalPrice*discount)<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"PayWave";
	for(int i=0;i<4;i++){
		sleep(1);
		cout<<".";
	}
	cout<<"\nTransaction completed.\nYour Credit Card has been charged."<<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales+=totalPrice-(totalPrice *discount);
	system("PAUSE");
	system("cls");
	mainMenu();
}
void eWallet(double totalPrice){
	system("cls");
	double discount = 0.03; 
	cout<<"You choose to pay using e-Wallet."<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Total           : RM "<<totalPrice<<endl;
	cout<<"Amount Due(-3%) : RM "<<totalPrice-(totalPrice*discount)<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Scanning QR Code";
	for(int i=0;i<4;i++){
		sleep(1);
		cout<<".";
	} 
	cout<<"\nTransaction completed. \nYour e-Wallet has been charged."<<endl;
	cout<<"\nThank you for using our service."<<endl;
	
	totalSales+=totalPrice-(totalPrice*discount);
	system("PAUSE");
	system("cls");
	mainMenu();
}
void paypal(double totalPrice) {
	system("cls");
	double discount = 0.02; 
	cout<<"You choose to pay using PayPal."<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Total           : RM "<<totalPrice<<endl;
	cout<<"Amount Due(-2%) : RM "<<totalPrice-(totalPrice*discount)<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Scanning QR Code";
	for(int i=0;i<4;i++){
		sleep(1);
		cout<<".";
	}
	cout<<"\nTransaction completed. \nYour PayPal has been deducted."<<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales+=totalPrice-(totalPrice*discount);
	system("PAUSE");
	system("cls");
	mainMenu();
}
//to display total sale for the day
void printTotSale(){
	system("cls");
	cout<<"+-----------------------------------+"<<endl;
	cout<<"|             Total Sale            |"<<endl;
	cout<<"+-----------------------------------+"<<endl;
	cout<<" \tTotal Sales    : RM "<<totalSales<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<" \tTotal Customer : "<<countCustomer<<endl;
	cout<<"-------------------------------------"<<endl;
	system("PAUSE");
	system("cls");
	adminPage();
}
//to display stock left
void printStock(){
	system("cls");
	cout<<"+-----------------------------------+"<<endl;
	cout<<"|     Total Stock of Potato Left    |"<<endl;
	cout<<"+-----------------------------------+"<<endl;
	cout<<"\t\t"<<stock<<endl;
	cout<<"-------------------------------------"<<endl;
	system("PAUSE");
	system("cls");
	adminPage();
}
//as a reference for the customer
void listCode(){
    cout<<"+----+-------------------+-----------------+-----------------+------------------+-------------------+"<<endl;
    cout<<"|CODE|    POTATO TYPE    |   POTATO SIZE   |   POTATO SIZE   |     TOPPING      |       SAUCE       |"<<endl;
    cout<<"+----+-------------------+-----------------+-----------------+------------------+-------------------+"<<endl;
    cout<<"|[1] | MASHED POTATO     | MEDIUM          | ORIGINAL        | CHILI FLAKES     | CHILI             |"<<endl;
    cout<<"|[2] | SPRING POTATO     | LARGE           | SPICY           | CHICKEN SLICE    | TOMATO            |"<<endl;
    cout<<"|[3] | CHIPS             |  -              | HOT & SPICY     | BLACK PAPER      | MAYONNAISE        |"<<endl;
    cout<<"|[4] | FRENCH FRIES      |  -              |  -              | BEEF BACON       | CHEESE            |"<<endl;
    cout<<"|[5] | WEDGES            |  -              |  -              | NONE             | THOUSAND ISLAND   |"<<endl;
    cout<<"|[6] |  -                |  -              |  -              |  -               | NONE              |"<<endl;
    cout<<"+----+-------------------+-----------------+-----------------+------------------+-------------------+"<<endl;
}
void logout(){
	system("cls");
	cout<<"+----------------------------------------+"<<endl;
	cout<<"|   Thank you for using Potato Machine   |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
	cout<<"\tProgram will terminated in\t "<<endl;
	cout<<"\tLoading";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<"\n+----------------------------------------+"<<endl;
	cout<<"|     PROGRAM TERMINATED SUCCESSFULLY    |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
}
