#include "../headers/handlers.hpp"
#include "../headers/core.hpp"
#include "../headers/user_handler.hpp"

string ReadInputs(const char *Msg)
{
  string TxtInput{""};

  cout<<Msg;
  getline(cin>>ws, TxtInput);
  
  return (TxtInput);
}

stClients RecordClientData(bool Trigger=true)
{
  stClients Cl;

  if (Trigger) {
    Cl.AccNum = ReadInputs("Enter account number: ");
  
    bool CheckAccNum = true;
  
    while (CheckAccNum) {
      for (const string &r:AccNums("Clients.txt")) {
	if (Cl.AccNum == r) {
	  Cl.AccNum = ReadInputs("Already Exists! re-Enter account number: ");
	  CheckAccNum = true;
	} else CheckAccNum = false;
      }
    }
  }
  
  Cl.PinCode = stoi(ReadInputs("Enter a pin code: "));
  Cl.CName = ReadInputs("Enter full client name: ");
  Cl.Phone = ReadInputs("Enter client phone number: ");
  Cl.Balance = stod(ReadInputs("Enter client balance: "));
  
  return (Cl);
}

string GetAccess()
{
  string Choice, ArrList[7] = {"[Display Table]", "[Insert Clients]", "[Update Client]", "[Find Client]", "[Delete Client]", "[Transactions]", "[Manage Users]"};
  uint16_t Counter = 0;

  for (; Counter <= 6; Counter++)
    Choice += ReadInputs(("Do you want Access on "+ArrList[Counter]+ "? (Y/N): ").c_str())[0];
  
  return (Choice);
}

uint16_t ApproveAccess()
{
  uint16_t i = 0, PermissionsCount = 0;
  string Choice = GetAccess();
  
  for (; i <= 6; i++) PermissionsCount += (Choice[i] == 'y' || Choice[i] == 'Y' ? pow(2, i) : 0);
  
  return (PermissionsCount);
}

stUsers RecUsrData(bool Trigger=false)
{
  stUsers Usr;
  string strMsg;
  
  if (Trigger == true) {
    strMsg = "Enter a username: ";

    do {
      Usr.Username = ReadInputs(strMsg.c_str());
    
      if (Usr.Username != "Admin" && Usr.Username != "admin" && Usr.Username != FetchUser(Usr.Username).Username) break;
      else strMsg = "Username is already allocated! please, re-enter a new username: ";
    
    } while (true);
  }
  
  Usr.Passwd = ReadInputs("Enter a password: ");

  strMsg = ReadInputs("Do you want full access on the system? (Y/N): ")[0];
  
  if (strMsg[0] == 'y' || strMsg[0] == 'Y') Usr.Permissions = 127;
  else Usr.Permissions = ApproveAccess();
 
  return (Usr);
}
