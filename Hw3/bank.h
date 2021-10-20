#pragma once
#ifndef _BANK_H_  
#define _BANK_H_  

void ShowMenu(void);  
void MakeAccount(void);  
void DepositMoney(void);  
void WithdrawMoney(void);  
void ShowAllAccInfo(void);
void History(void);
void DeleteAccount(void);
void DeleteAll(void);
int GetAccIdx(int);  


enum class bank{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, HISTORY, DELETEACCOUNT, DELETEALL, EXIT };  
const int NAME_LEN = 40;  
const int MAX_ACC_NUM = 100;  

typedef struct{ 
	int accID; 
    int password;
    int balance; 
    int historyOfDeposit;
    int historyOfWithdrawal;
    char cusName[NAME_LEN]; 
}Account;  
#endif //_BANK_H_