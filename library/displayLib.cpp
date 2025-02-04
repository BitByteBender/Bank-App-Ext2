#include "../headers/displayLib.hpp"


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

  string SplitChunks(vector <string> Line)
  {
    string Ln;

    Ln = MenuSpacer(Line[0], 20);
    Ln += MenuSpacer(Line[1], 18);
    Ln += MenuSpacer(Line[2], 17);
    Ln += Line[3];
 
    return (Ln);
  }

  string GetUsersLine(vector <string> Line)
  {
    string Ln;
    
    Ln = MenuSpacer(Line[0], 26);
    Ln += MenuSpacer(Line[1], 27);
    Ln += Line[2];
    
    return (Ln);
  }
  
  vector <string> vGeneralMerger(vector <string> vLines, char Choice)
  {
    vector <string> vContainer;
    vector <string>::iterator iter;

    for (iter = vLines.begin(); iter != vLines.end(); iter++) {
      if (Choice == 'T') vContainer.push_back(SplitChunks(SplitLine(*iter, "#-#")));
      else vContainer.push_back(GetUsersLine(SplitLine(*iter, "#-#")));
    }

    return (vContainer);
  }
  
  void DisplayClientRecord(stClients Client, bool Trigger=false)
  {
    if (Trigger == true) cout<<"Account Number: "<<Client.AccNum<<'\n';
    cout<<"Pin code: "<<Client.PinCode<<'\n'
	<<"Fullname: "<<Client.CName<<'\n'
	<<"Phone Number: "<<Client.Phone<<'\n'
	<<"Balance: "<<Client.Balance<<endl;
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

  void DisplayMultipleVMenuWrapper(const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive=false, bool Toggle=true)
  {
    vector <stClients> vClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
    DisplayMenuTop(Style, BorderCount, HeaderName, isActive);

    for (const stClients &r:vClients) {
      if (Toggle) {
	cout<<"  "<<MenuSpacer(r.AccNum, 17);
	cout<<" "<<MenuSpacer(to_string(r.PinCode), 12);
	cout<<" "<<MenuSpacer(r.CName, 19);
	cout<<" "<<MenuSpacer(r.Phone, 19);
	cout<<" "<<r.Balance<<'\n';
      } else {
	cout<<"  "<<MenuSpacer(r.AccNum, 20);
	cout<<" "<<MenuSpacer(r.CName, 30);
	cout<<" "<<r.Balance<<'\n';
      }
    }
    
    cout<<BorderCounter(Style, BorderCount)<<endl;
  }

  void DisplayMultipleVMenuWrapperV2(const char *Func, const char *Style, uint16_t BorderCount, const char *HeaderName, bool isActive=false)
  {
    string keyword = "Trx";
    vector <string> vContainer;    
    DisplayMenuTop(Style, BorderCount, HeaderName, isActive);

    if (Func == keyword.c_str()) {
      vContainer = displayLib::vGeneralMerger(LoadFromFile("0-Trx.txt"), 'T');
      for (const string &r:vContainer) cout<<"  "<<r<<'\n';
    } else {
      vContainer = displayLib::vGeneralMerger(LoadFromFile("Users.txt"), 'U');
      for (const string &r:vContainer) cout<<"  "<<r<<'\n';
    }
    
    cout<<BorderCounter(Style, BorderCount)<<endl;
  }

  void DisplayEndResutl(string AccNum, string Choice, uint16_t Balance)
  {
    cout<<"\nAccount ["<<AccNum
	<<"] has a new "<<Choice<<"!"<<'\n'
	<<">> New Balance of ["<<AccNum<<"] is: "
	<<Balance<<endl;
  }
 }
