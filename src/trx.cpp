#include "../headers/displayLib.hpp"
#include "../headers/core.hpp"

void TrxMenu(uint16_t OperationChoice)
{
  switch (OperationChoice) {
  case (enTrxOps::Deposit):
    DepositToAccount();
    break;
  case (enTrxOps::Withdraw):
    WithdrawFromAccount();
    break;
  case (enTrxOps::ViewBalances):
    DisplayTable("Balances", "-", 90, false, false);
    break;
  default:
    cout<<"Nothing is built yet!"<<endl;
  }
}

void TrxMenuTrigger()
{
  uint16_t Choice = 0;
  displayLib::DisplayMenuWrapper("x", 35, "Trx Menu", 5, "1: Deposit, 2: Withdraw, 3: View Balances, 4: Main Menu", true);
  
  do {
    Choice = stoi(ReadInputs(">> Choose from the transaction menu: "));

    if (Choice == 4) break;
    if (Choice >= 1 && Choice <= 3) {
      TrxMenu(Choice);
      cout<<"\nPress enter to go back to trx menu ..."<<endl;
      cin.get();
      displayLib::DisplayMenuWrapper("x", 35, "Trx Menu", 5, "1: Deposit, 2: Withdraw, 3: View Balances, 4: Main Menu", true);
    } else cout<<"[Warning]: This option is not in the transaction menu!\n\n";
    
  } while (true);
}
