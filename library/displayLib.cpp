#include "../headers/displayLib.hpp"
/*#include "../headers/handlers.hpp"
#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>

using std::cout;
using std::endl;
using std::vector;*/

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

  stClients SplitLineToRec(vector <string> vChunks)
  {
    stClients Cl;

    Cl.AccNum = vChunks[0];
    Cl.PinCode = stoi(vChunks[1]);
    Cl.CName = vChunks[2];
    Cl.Phone = vChunks[3];
    Cl.Balance = stod(vChunks[4]);
    
    return (Cl);
  }
  
  vector <string> SplitLine(string Line, string DELIM)
  {
    vector <string> vClient;
    short pos = Line.find(DELIM);

    while (pos != string::npos) {
      vClient.push_back(Line.substr(0, pos));
      Line.erase(0, pos + DELIM.length());
      pos = Line.find(DELIM);
    }

    if (Line != "") {
      vClient.push_back(Line);
      Line.clear();
    }
    
    return (vClient);
  }

  vector <stClients> LineToRec(vector <string> vLines)
  {
    vector <stClients> vClientRecs;
    vector <string>::iterator iter;
    
    for (iter = vLines.begin(); iter != vLines.end(); iter++) {
      vClientRecs.push_back(SplitLineToRec(SplitLine(*iter, "#-#")));
    }
    
    return (vClientRecs);
  }

  string MenuSpacer(string Val, uint16_t Limiter)
  {
    string Container = Val;
    uint16_t i = 0, Spaces = Limiter - Container.length();
    
    for (i = 0; i < Spaces; ++i) {
      Container += " ";
    }
    
    return (Container);
  }
  
  void DisplayMultipleVMenuWrapper(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive=false)
  {
    vector <stClients> vClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
    DisplayMenuTop(Style, BorderCount, HeaderName, isActive);

    for (const stClients &r:vClients) {
      cout<<"  "<<MenuSpacer(r.AccNum, 17);
      cout<<" "<<MenuSpacer(to_string(r.PinCode), 12);
      cout<<" "<<MenuSpacer(r.CName, 19);
      cout<<" "<<MenuSpacer(r.Phone, 19);
      cout<<" "<<r.Balance<<'\n';
    }
    
    cout<<BorderCounter(Style, BorderCount)<<endl;
  }
  }
