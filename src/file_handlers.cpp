#include "../headers/handlers.hpp"


string RecToLine(stClients Cl, string DELIM)
{
  string Line;

  Line = Cl.AccNum + DELIM;
  Line += to_string(Cl.PinCode) + DELIM;
  Line += Cl.CName + DELIM;
  Line += Cl.Phone + DELIM;
  Line += to_string(Cl.Balance);
  
  return (Line);
}

vector <string> RecsToLines(vector <stClients> &vClients)
{
  vector <string> vLines;

  for (const stClients &rec:vClients) {
    vLines.push_back(RecToLine(rec, "#-#"));
  }
  
  return (vLines);
}

void SaveRecToFile(vector <string> &vClients, string fname)
{
  fstream File;

  File.open(fname, ios::out);

  if (File.is_open()) {
    for (const string &rec:vClients) {
      if (!rec.empty())
	File<<rec<<'\n';
    }
    
    File.close();
  }
}

void SaveSingleRecToFile(string Line, string fname)
{
  fstream File;

  File.open(fname, ios::out | ios::app);

  if (File.is_open()) {
    if (!Line.empty())
	File<<Line<<'\n';
    
    File.close();
  }
}

vector <string> LoadFromFile(string fname)
{
  fstream File;
  vector <string> vClients;
  
  File.open(fname, ios::in);

  if (File.is_open()) {
    string Line;
    while (getline(File, Line)) {
      if (Line != "") {
	vClients.push_back(Line);
      }
    }
    File.close();
  }

  return (vClients);
}

vector <string> AccNums(string fname)
{
  vector <string> vAccNums;
  short pos;
  
  for (const string &ln:LoadFromFile(fname)) {
    pos = ln.find("#-#");
    vAccNums.push_back(ln.substr(0, pos));
  }
	 
  return (vAccNums);
}

// Method to fetch a record with same (AccNum) inside the file then remove it if found!
string LineFilter(string Record)
{
  string Line;
  return (Line = Record.substr(0, Record.find("#-#")));
}

vector <string> VerifyAccNums(string fname)
{
  vector <string> vClients = LoadFromFile(fname), vNewRecs;
  
  for (const string &r:vClients) {
    short i = 0;
    vNewRecs.push_back(r);
    for (const string &an:vNewRecs) {
      if (LineFilter(r) == LineFilter(an)) ++i;
      
      if (i > 1) {
	vNewRecs.pop_back();
	break;
      }
    }
  }
  
  return (vNewRecs);
}

string TrxLines(stClients Cl, string Amount, string DELIM)
{
  string Line;
  
  Line = Cl.AccNum + DELIM;
  Line += Amount + DELIM;
  Line += (Amount[0] == '+' ? "Deposit" : "Withdraw") + DELIM;
  Line += to_string(Cl.Balance);
    
  return (Line);
}

uint16_t RecCounter(vector <string> &vRec)
{
  uint16_t counter = 0;
  
  for (const string &rec:vRec) {
   if (rec != "") counter++;
  }

  return (counter);
}

string RecToLine(stUsers Usr, string DELIM)
{
  string Line;

  Line = Usr.Username + DELIM + Usr.Passwd + DELIM + to_string(Usr.Permissions);
  
  return (Line);
}
