#include "../headers/core.hpp"
#include "../headers/user_handler.hpp"
#include "../headers/handlers.hpp"
#include "../headers/displayLib.hpp"

void UserManagerMenu(uint16_t OperationChoice)
{
  switch (OperationChoice) {
  case (enUsrManagerOps::ViewUsrs):
    DisplayUsrTable("-", 75, false);
    break;
  case (enUsrManagerOps::AddUsr):
    AddNewUsr();
    break;
  case (enUsrManagerOps::DeleteUsr):
    cout<<"Nothing here\n";
    break;
  case (enUsrManagerOps::UpdateUsr):
    cout<<"Nothing here\n";
    break;
  case (enUsrManagerOps::FindUsr):
    cout<<"Nothing here\n";
    break;
  default:
    cout<<"Option is Not in User Manager menu!\n"<<endl;
  }
}

void UserManagerTrigger()
{
  char Choice;
  
  do {
    displayLib::DisplayMenuWrapper("x", 35, "Trx Menu", 5, "1: View Users, 2: Add New User, 3: Delete User, 4: Update User, 5: Find User, 6: Back To Main Menu", true);
    Choice = ReadInputs(">> Choose from the user menu: ")[0];
    if (uint16_t(Choice) == 54) break;
    
    if (uint16_t(Choice) > 48 && uint16_t(Choice) <= 53) {
      UserManagerMenu(uint16_t(Choice) - 48);
      cout<<"Hit [Enter] to go back to user menu\n";
      cin.get();
    } else cout<<"[Warning]: This Option is not in the User Manager Menu!\n\n";
    
  } while (uint16_t(Choice) != 54);
}
