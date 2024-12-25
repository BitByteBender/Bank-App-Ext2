#include "../headers/displayLib.hpp"
#include <iostream>
#include <cmath>
#include <cstdint>
using std::cout;
using std::endl;

namespace displayLib
{
  string BorderCounter(const char *Style, uint16_t NumCount = 0)
  {
    uint16_t i = 0;
    string Border = "";
    
    for (i = 0; i < NumCount; ++i)
      Border += Style;

    return (Border);
  }
  
  uint16_t CountStr(string str)
  {
    uint16_t TotalCount = 0;

    while (!str.empty()) {
      TotalCount++;
      str.pop_back();
    }
    
    return (TotalCount);
  }
  
  string Spacer(uint16_t BorderCount, uint16_t HeaderNameCount)
  {
    return (BorderCounter(" ", abs((BorderCount / 2) - (HeaderNameCount / 2))));
  }

  void DisplayMenuTop(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive=false)
  {
    string MenuBorder = BorderCounter(Style, BorderCount), strSpacer = Spacer(CountStr(MenuBorder), CountStr(HeaderName));
    cout<<MenuBorder<<'\n';
    if (isActive)
      cout<<strSpacer;
    cout<<HeaderName<<strSpacer<<'\n'
	<<MenuBorder<<'\n';
  }


  void DisplayMenuCore(string Core, uint16_t Spaces)
  {
    short pos = 0;
    string Delim = ", ";
    
    while ((pos = Core.find(Delim)) != string::npos) {
      cout<<BorderCounter(" ", Spaces)<<Core.substr(0, pos)<<'\n';
      Core.erase(0, pos + Delim.length());
    }

    if (!Core.empty()) {
      cout<<BorderCounter(" ", Spaces)<<Core<<'\n';
    }
  }
  
  void DisplayMenuWrapper(const char *Style, uint16_t BorderCount, const char *HeaderName, uint16_t Spaces, string Core, bool isActive=false)
  {
    DisplayMenuTop(Style, BorderCount, HeaderName, isActive);
    DisplayMenuCore(Core, Spaces);
    cout<<BorderCounter(Style, BorderCount)<<endl;
  }
  }
