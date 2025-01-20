#include "../headers/core.hpp"
#include "../headers/displayLib.hpp"

void MenuOperations(uint16_t OperationChoice)
{

  switch (OperationChoice) {
    /*case (enOps::MainMenu):
    displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client", true);
    break;*/
  case (enOps::View):
    DisplayTable("-", 90, false);
    break;
  case (enOps::Insert):
    InsertClients();
    break;
  case (enOps::Update):
    UpdateClient();
    break;
  default:
    cout<<"Nothing Implemented Here\n"<<endl;
  }
}


void ChoicePicker()
{
  char Choice = ReadInputs(">> Choose from the main menu: ")[0];
  
  if (uint16_t(Choice) > 48 && uint16_t(Choice) <= 51) {
    MenuOperations(uint16_t(Choice) - 48);
    cout<<"\nHit enter to go back to main menu...\n";
    cin.get();
    displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client, 3: Update Client", true);
  } else cout<<"\n[Warning]>> That's not a choice in the main menu!\n";
}

void SysTrigger()
{
  displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client, 3: Update Client", true);
  while (true) {
    ChoicePicker();
  }
}
