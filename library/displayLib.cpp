#include "../headers/displayLib.hpp"
#include <iostream>

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

    while (str != "") {
      TotalCount++;
      str.pop_back();
    }
    
    return (TotalCount);
  }
  
  string Spacer(uint16_t BorderCount, uint16_t HeaderNameCount)
  {
    return (BorderCounter(" ", (BorderCount / 2) - (HeaderNameCount / 2)));
  }

  void DisplayMenuTop(uint16_t BorderCount, const char *HeaderName)
  {
    string MenuBorder = BorderCounter("-", BorderCount), strSpacer = Spacer(CountStr(MenuBorder), CountStr(HeaderName));
    cout<<MenuBorder<<'\n'
	<<strSpacer<<HeaderName<<strSpacer<<'\n'
	<<MenuBorder<<'\n';
    
  }

}
