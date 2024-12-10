#include <iostream>
#include "../headers/displayLib.hpp"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using displayLib::BorderCounter;
using displayLib::Spacer;
using displayLib::CountStr;

void DisplayTableTop(void)
{
  uint16_t ClientsCount = 0;
  string strHeader = "Client List (" + to_string(ClientsCount) + ") Client(s).", MenuBorder = BorderCounter("-", 15);
  cout<<Spacer(CountStr(MenuBorder), CountStr(strHeader))<<strHeader<<'\n';
}
