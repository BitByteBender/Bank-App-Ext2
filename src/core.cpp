#include "../headers/core.hpp"
#include "../headers/displayLib.hpp"

void MenuOperations(uint16_t OperationChoice)
{

  switch (OperationChoice) {
  case (enOps::MainMenu):
    displayLib::DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client", true);
    break;
  case (enOps::CMenu):
    DisplayTable("-", 90, false);
    break;
  }
}
