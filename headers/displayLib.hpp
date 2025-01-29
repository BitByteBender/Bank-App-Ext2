#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H

#include "../headers/handlers.hpp"
#include <iostream>
#include <cmath>
#include <cstdint>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace displayLib
{
  string BorderCounter(const char *Style, uint16_t NumCount);
  uint16_t CountStr(string str);
  string Spacer(uint16_t BorderCount, uint16_t HeaderNameCount);
  void DisplayMenuTop(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive);
  void DisplayMenuCore(string Core, uint16_t Spaces);
  stClients SplitLineToRec(vector <string> vChunks);
  vector <string> SplitLine(string Line, string DELIM);
  vector <stClients> LineToRec(vector <string> vLines);
  void DisplayClientRecord(stClients Client, bool Trigger);
  void DisplayMenuWrapper(const char *Style, uint16_t BorderCount, const char *HeaderName, uint16_t Spaces, string Core, bool isActive);
  string MenuSpacer(string Val, uint16_t Limiter);
  void DisplayMultipleVMenuWrapper(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive, bool Toggle);
  void DisplayEndResutl(string AccNum, string Choice, uint16_t Balance);
  void DisplayMultipleVMenuWrapperV2(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive);
}

#endif /* DISPLAYLIB_H */
