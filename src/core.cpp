#include "../headers/core.hpp"
#include "../headers/displayLib.hpp"
#include "../headers/user_handler.hpp"

void MenuOperations(uint16_t OperationChoice)
{
  string InputStr;
  
  switch (OperationChoice) {
    /*case (enOps::MainMenu):
    displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client", true);
    break;*/
  case (enOps::View):
    DisplayTable("Clients", "-", 90, false, true);
    break;
  case (enOps::Insert):
    InsertClients();
    break;
  case (enOps::Update):
    UpdateClient();
    break;
  case (enOps::Find):
    InputStr = "Enter an account number you want to check: ";
    FindClient(ReadInputs(InputStr.c_str()), 0);
    break;
  case (enOps::Delete):
    DeleteClient();
    break;
  case (enOps::Trx):
    //InputStr = ReadInputs("Choose? ");
    TrxMenuTrigger();
    break;
  case (enOps::UsrManager):
    //Missing implementation
    cout<<"Still under development!\n"<<endl;
    break;
  case (enOps::Logout):
    //This needs to be rerouted to a user login page
    cout<<"Logout Successful!"<<endl;
    OnAuthentication();
    exit(0);
  default:
    cout<<"Nothing Implemented Here\n"<<endl;
  }
}

void WarningFiltrator(uint16_t Choice, uint16_t From, uint16_t To)
{
  if (Choice > From && Choice <= To) cout<<"Access Denied!\n\n";
  else cout<<"\n[Warning]>> That's not a choice in the main menu!\n";
}

void ChoicePicker(short Permissions)
{
  char Choice = ReadInputs(">> Choose from the main menu: ")[0];
  string Validate = RetrieveChoicesV2(Permissions);
  
  if (uint16_t(Choice) == 56) {
    MenuOperations(uint16_t(Choice) - 48);
  } else {
    // missing Admin validations
    if (uint16_t(Choice) > 48 && uint16_t(Choice) <= 55 && Validate[8 - (uint16_t(Choice) - 48)] == '1') {
      MenuOperations(uint16_t(Choice) - 48);
      cout<<"\nHit enter to go back to main menu...\n";
      cin.get();
      displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client, 3: Update Client, 4: Find Client, 5: Delete Client, 6: Transactions, 7: User Manager, 8: Logout", true);
    } else WarningFiltrator(Choice, 48, 56);
  }
}

void SysTrigger(stUsers Usr)
{
  displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client, 3: Update Client, 4: Find Client, 5: Delete Client, 6: Transactions, 7: User Manager, 8: Logout", true);
  while (true) {
    ChoicePicker(Usr.Permissions);
  }
}

void OnAuthentication()
{
  uint16_t i = 0;
  
  while (true) {
    string Usrname = ReadInputs("Username: "), Passwd = ReadInputs("Password: ");
    if (i == 3) break;
    if (AuthenticateUser(Usrname, Passwd)) SysTrigger(FetchUser(Usrname));
    else {
      cout<<"\nAccess Denied!\n[You have "
	  <<abs(i-3)<<" attemtpts left!]"<<endl;
      ++i;
    }
  }
}
