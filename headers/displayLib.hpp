#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H

#include <string>

using std::string;

namespace displayLib
{
  string BorderCounter(const char *Style, uint16_t NumCount);
  uint16_t CountStr(string str);
  string Spacer(uint16_t BorderCount, uint16_t HeaderNameCount);
  void DisplayMenuTop(uint16_t BorderCount, const char *HeaderName);
}

#endif /* DISPLAYLIB_H */
