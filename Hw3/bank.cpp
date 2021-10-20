#include <iostream>  
#include "bank.h"  
using namespace std;
Account accArr[MAX_ACC_NUM]; //Account array  
int accNum=0; //# of accounts  

void ShowMenu(void){  
	cout << "-----Menu------" << endl;
	cout << "1.Make Accout" << endl;
	cout << "2.Deposit" << endl;
	cout << "3.Withdrawal" << endl;
	cout << "4.Display all" << endl;
	cout << "5.Account History" << endl;
	cout << "6.Delete Account" << endl;
	cout << "7.Delete All Accounts" << endl;
	cout << "8.Exit program" << endl;
}  
void MakeAccount(void){  
	int id,password;  
	char name[NAME_LEN];  
	int balance;  
	if(accNum>=MAX_ACC_NUM){  
		cout << "Sorry! cannot make an accout anymore." << endl;
		return; 
	}  
	if (accNum == -1) {
		accNum = 0;
	}
	cout << "[Make Account]" << endl;
	cout << "Account ID:";
	cin >> id;
	cout << "Account Password:";
	cin >> password;
	
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	
	cout<<endl;  
	if(GetAccIdx(id) != -1){  
		cout<<"Error: Existing account ID"<<endl;  
		return;  
	}  
	
	accArr[accNum].accID=id; 
	accArr[accNum].password = password;
	accArr[accNum].balance=balance; 
	accArr[accNum].historyOfDeposit += balance;
	strcpy(accArr[accNum].cusName,name);  
	accNum++;  
}
void DepositMoney(void) { 
	int money;  
	int id,password;  
	cout << "[Deposit]" << endl; 
	cout << "AccountID:";  
	cin >> id;  
	cout << "Account Password:";
	cin >> password;
	cout << "Deposit amount:";  
	cin >> money;  
	for (int i = 0; i < accNum; i++) { 
		if (accArr[i].accID == id && accArr[i].password == password) {
			accArr[i].balance += money;  
			cout << "Deposit completed" << endl << endl;  
			accArr[i].historyOfDeposit += money;
			return; 
		} 
	}  
	cout << "This ID is not valid." << endl << endl; 
}  
void WithdrawMoney(void) { 
	int money;  
	int id, password;  
	cout << "[Withdrawal]" << endl; 
	cout << "Account ID:";  
	cin >> id;  
	cout << "Account Password:";
	cin >> password;
	cout << "Withdrawal amount:";  
	cin >> money;  
	for (int i = 0; i < accNum; i++) { 
		if (accArr[i].accID == id && accArr[i].password == password) {
			if (accArr[i].balance < money) { 
				cout << "Not enough balance" << endl << endl;  
				return; 
			}  
			accArr[i].balance -= money;  
			cout << "Withdrawal completed" << endl << endl; 
			accArr[i].historyOfWithdrawal += money;
			return; 
		} 
	}  
	cout << "This ID is not valid." << endl << endl; 
}
void ShowAllAccInfo(void) { 
	for (int i = 0; i < accNum; i++) { 
		cout << "Account ID:" << accArr[i].accID << endl;
		cout << "Name:" << accArr[i].cusName << endl; 
		cout << "Balance:" << accArr[i].balance << endl << endl; 
	} 
}  
void History(void) {
	int id, password;
	cout << "[History]" << endl;
	cout << "Account ID:";
	cin >> id;
	cout << "Account Password:";
	cin >> password;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id && accArr[i].password == password) {
			cout << "Total amount of deposit: " << accArr[i].historyOfDeposit << endl;
			cout << "Total amount of withdrawal: " << accArr[i].historyOfWithdrawal << endl;
		}
	}

}
int GetAccIdx(int id) { 
	for (int i = 0; i < accNum; i++) { 
		if (accArr[i].accID == id) { 
			return i; 
		} 
	}  return-1; 
}
void DeleteAccount(void) {
	int id, password;
	cout << "[Delete Account]" << endl;
	cout << "Account ID:";
	cin >> id;
	cout << "Account Password:";
	cin >> password;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id && accArr[i].password == password) {
			accArr[i].accID = NULL;
			strcpy(accArr[i].cusName, "\0");
			accArr[i].balance = NULL;			
			cout << "Account Deleted!" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}
void DeleteAll(void) {
	cout << "[Delete All Accounts]" << endl;
	for (int i = 0; i < accNum; i++) {
			accArr[i].accID = NULL;
			strcpy(accArr[i].cusName,"\0");
			accArr[i].balance = NULL;
								
	}
	accNum = -1;
	cout << "All Accounts Deleted!" << endl << endl;
	return;
}

	
