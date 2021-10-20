#include <iostream>  
#include "bank.h"  
using namespace std;  
int main(void){  
	int choice;  
	while(1){  
		system("cls");
		ShowMenu();  
		cout<<"Select menu:";  
		cin>>choice;  
		cout<<endl;  
		switch(bank(choice)){  
			case bank::MAKE:  
				MakeAccount(); 
				system("pause");
				break;  
			case bank::DEPOSIT:  
				DepositMoney(); 
				system("pause");
				break;  
			case bank::WITHDRAW:  
			    WithdrawMoney();  
				system("pause");
			    break;  
			case bank::INQUIRE: 
			    ShowAllAccInfo(); 
				system("pause");
			    break;  
			case bank::HISTORY:
				History();
				system("pause");
				break;
			case bank::DELETEACCOUNT:
				DeleteAccount();
				system("pause");
				break;
			case bank::DELETEALL:
				DeleteAll();
				system("pause");
				break;
			case bank::EXIT:  
			    return 0;  
			default:  
				cout<<"Illegal selection.."<<endl;  
		}  
	}  
	return 0;  
}