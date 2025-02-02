#include "../headers/core.hpp"
#include "../headers/user_handler.hpp"
#include "../headers/handlers.hpp"

void UserManagerMenu(uint16_t OperationChoice)
{
  switch (OperationChoice) {
  case (enUsrManagerOps::ViewUsrs):
    cout<<"Nothing here\n";
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
  char Choice = ReadInputs(">> Choose from the user menu: ")[0];
  
  do {
    if (uint16_t(Choice) == 54) break;
    
    if (uint16_t(Choice) > 48 && uint16_t(Choice) <= 53) {
      UserManagerMenu(uint16_t(Choice) - 48);
      cout<<"Hit [Enter] to go back to user menu\n";
      cin.get();
    } else cout<<"[Warning]: This Option is not in the User Manager Menu!\n\n";
    
    Choice = ReadInputs(">> Choose from the user menu: ")[0];
  } while (uint16_t(Choice) != 54);
}
