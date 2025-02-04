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
using displayLib::DisplayMultipleVMenuWrapperV2;

void DisplayTable(const char *TableType, const char *Style, uint16_t BorderCount, bool isActive=false, bool Toggle=true)
{
  vector <string> vRec = VerifyAccNums("0-Dupes_Clients.txt");
  uint16_t ClientsCount = RecCounter(vRec);
  const char *strMidHeader = "";
  string strHeader(TableType), MenuBorder = BorderCounter(Style, BorderCount);;
  strHeader += " List (" + to_string(ClientsCount) + ") Client(s).";
 
  cout<<Spacer(CountStr(MenuBorder), CountStr(strHeader))<<strHeader<<'\n';

  if (Toggle == true)
    strMidHeader = "| Account Number  | Pin Code   | Client Name       | Phone             | Balance    ";
  else
    strMidHeader = "| Account Number     | Client Name                  | Balance    ";
  
  DisplayMultipleVMenuWrapper(Style, BorderCount, strMidHeader, isActive, Toggle);
}

void DisplayTrxTable(const char *Style, uint16_t BorderCount, bool isActive=false)
{
  vector <string> vRec = LoadFromFile("0-Trx.txt");
  uint16_t TrxCount = RecCounter(vRec);

  string TabTop, TabHeader = "Transactions List ("+to_string(TrxCount)+") Done.";

  cout<<"\n\n"<<Spacer(CountStr(BorderCounter(Style, BorderCount)), CountStr(TabHeader))
      <<TabHeader<<'\n';

  TabTop = "| Account Number    | In/out          | Trx Type       | New Balance    ";
  DisplayMultipleVMenuWrapperV2("Trx", Style, BorderCount, TabTop.c_str(), isActive);
}

void DisplayUsrTable(const char *Style, uint16_t BorderCount, bool isActive=false)
{
  vector <string> vRec = LoadFromFile("Users.txt");
  uint16_t UsrCount = RecCounter(vRec);

  string TabTop, TabHeader = "Users List ("+to_string(UsrCount)+") Done.";

  cout<<"\n\n"<<Spacer(CountStr(BorderCounter(Style, BorderCount)), CountStr(TabHeader))
      <<TabHeader<<'\n';

  TabTop = "| Username                | Password                 | Permissions    ";
  DisplayMultipleVMenuWrapperV2("Usr", Style, BorderCount, TabTop.c_str(), isActive);
}
