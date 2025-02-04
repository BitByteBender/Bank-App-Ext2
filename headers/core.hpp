#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;
using std::to_string;
using std::vector;
using std::ios;
using std::fstream;

enum enOps { View = 1, Insert = 2 , Update = 3, Find = 4, Delete = 5, Trx = 6, UsrManager = 7, Logout = 8 };

enum enTrxOps { Deposit = 1, Withdraw = 2, ViewBalances = 3, TRXs = 4};

enum enUsrManagerOps { ViewUsrs = 1, AddUsr = 2, DeleteUsr = 3, UpdateUsr = 4, FindUsr = 5};

struct stClients
{
  string AccNum;
  uint16_t PinCode;
  string CName, Phone;
  double Balance;
};

struct stUsers
{
  string Username, Passwd;
  int16_t Permissions = -1;
};

void DisplayTable(const char *TableType, const char *Style, uint16_t BorderCount, bool isActive, bool Toggle);
void DisplayTrxTable(const char *Style, uint16_t BorderCount, bool isActive);
void DisplayUsrTable(const char *Style, uint16_t BorderCount, bool isActive);

//Main Menu
void MenuOperations(uint16_t OperationChoice);
void ChoicePicker();

//Trx Menu
void TrxMenu(uint16_t OperationChoice);
void TrxMenuTrigger();

void SysTrigger();
void OnAuthentication();
#endif /*CORE_H*/
