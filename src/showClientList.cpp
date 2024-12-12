#include <iostream>
#include "../headers/displayLib.hpp"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using displayLib::BorderCounter;
using displayLib::Spacer;
using displayLib::CountStr;
using displayLib::DisplayMenuWrapper;

void DisplayTable(const char *Style, uint16_t BorderCount, bool isActive=false)
{
  // For testing must be replaced with a function
  uint16_t ClientsCount = 0;
  const char *strMidHeader = "";
  string strHeader = "Client List (" + to_string(ClientsCount) + ") Client(s).", MenuBorder = BorderCounter(Style, BorderCount);
 
  cout<<Spacer(CountStr(MenuBorder), CountStr(strHeader))<<strHeader<<'\n';
  
  strMidHeader = "| Account Number  | Pin Code   | Client Name       | Phone             | Balance    ";
  DisplayMenuWrapper(Style, BorderCount, strMidHeader, 0, "Test", isActive);
}
