#include <iostream>
#include "headers/displayLib.hpp"

using std::cout;
using std::endl;
using displayLib::BorderCounter;
using displayLib::CountStr;
using displayLib::Spacer;
using displayLib::DisplayMenuTop;

int main(void)
{
  cout<<BorderCounter("#", 25)<<endl;
  cout<<CountStr(BorderCounter("Y", 25))<<endl;
  cout<<CountStr("MayorSlayer")<<endl;
  cout<<Spacer(CountStr(BorderCounter("-", 25)), CountStr("MayorSlayer"))
      <<"MayorSlayer"
      <<Spacer(CountStr(BorderCounter("-", 25)), CountStr("MayorSlayer"))<<endl;
  cout<<BorderCounter("#", 25)<<endl;


  DisplayMenuTop(35, "Main Menu");
  return (0);
}

