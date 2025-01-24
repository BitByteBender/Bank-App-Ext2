#include <iostream>
#include "../headers/displayLib.hpp"
#include "../headers/handlers.hpp"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using displayLib::BorderCounter;
using displayLib::Spacer;
using displayLib::CountStr;
using displayLib::DisplayMenuWrapper;
using displayLib::DisplayMultipleVMenuWrapper;

void DisplayTable(const char *TableType, const char *Style, uint16_t BorderCount, bool isActive=false, bool Toggle=true)
{
  uint16_t Count = ClientsCounter();
  const char *strMidHeader = "";
  string strHeader(TableType), MenuBorder = BorderCounter(Style, BorderCount);;
  strHeader += " List (" + to_string(Count) + ") Client(s).";
 
  cout<<Spacer(CountStr(MenuBorder), CountStr(strHeader))<<strHeader<<'\n';

  if (Toggle == true)
    strMidHeader = "| Account Number  | Pin Code   | Client Name       | Phone             | Balance    ";
  else
    strMidHeader = "| Account Number     | Client Name                  | Balance    ";
  
  DisplayMultipleVMenuWrapper(Style, BorderCount, strMidHeader, isActive, Toggle);
}
