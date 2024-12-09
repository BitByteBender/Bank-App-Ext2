#include <iostream>
#include "headers/displayLib.hpp"

using std::cout;
using std::endl;
using displayLib::BorderCounter;
using displayLib::CountStr;
using displayLib::Spacer;
using displayLib::DisplayMenuTop;
using displayLib::DisplayMenuCore;
using displayLib::DisplayMenuWrapper;

int main(void)
{
  /*
  cout<<BorderCounter("#", 25)<<endl;
  cout<<CountStr(BorderCounter("Y", 25))<<endl;
  cout<<CountStr("MayorSlayer")<<endl;
  cout<<Spacer(CountStr(BorderCounter("-", 25)), CountStr("MayorSlayer"))
      <<"MayorSlayer"
      <<Spacer(CountStr(BorderCounter("-", 25)), CountStr("MayorSlayer"))<<endl;
  cout<<BorderCounter("#", 25)<<endl;

  DisplayMenuTop("x", 35, "Main Menu");
  cout<<"\n\n";
  DisplayMenuCore("1: Test1, 2: Testt2, 3: Tessst 4");
  */
  DisplayMenuWrapper("x", 35, "Main Menu", 15, "1: Test1, 2: Testt2, 3: Tessst 3, 4: T e s t4, 5: Te st 5");
  return (0);
}
