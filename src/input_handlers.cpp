#include "../headers/handlers.hpp"
#include "../headers/core.hpp"

string ReadInputs(const char *Msg)
{
  string TxtInput{""};

  cout<<Msg;
  getline(cin>>ws, TxtInput);
  
  return (TxtInput);
}

stClients RecordClientData()
{
  stClients Cl;

  Cl.AccNum = ReadInputs("Enter account number: ");
  bool CheckAccNum = true;
  
  while (CheckAccNum) {
    for (const string &r:AccNums()) {
      if (Cl.AccNum == r) {
	Cl.AccNum = ReadInputs("Already Exists! re-Enter account number: ");
	CheckAccNum = true;
      } else CheckAccNum = false;
    }
  }
  Cl.PinCode = stoi(ReadInputs("Enter a pin code: "));
  Cl.CName = ReadInputs("Enter full client name: ");
  Cl.Phone = ReadInputs("Enter client phone number: ");
  Cl.Balance = stod(ReadInputs("Enter client balance: "));
  
  return (Cl);
}
