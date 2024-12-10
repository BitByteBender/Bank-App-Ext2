#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H

#include <string>

using std::string;

namespace displayLib
{
  string BorderCounter(const char *Style, uint16_t NumCount);
  uint16_t CountStr(string str);
  string Spacer(uint16_t BorderCount, uint16_t HeaderNameCount);
  void DisplayMenuTop(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive);
  void DisplayMenuCore(string Core, uint16_t Spaces);
  
  void DisplayMenuWrapper(const char *Style, uint16_t BorderCount, const char *HeaderName, uint16_t Spaces, string Core, bool isActive);
  
}

#endif /* DISPLAYLIB_H */
