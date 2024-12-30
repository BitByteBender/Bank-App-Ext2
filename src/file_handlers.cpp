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

void SaveRecToFile(vector <string> &vClients, string fname)
{
  fstream File;

  File.open(fname, ios::out | ios::app);

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

vector <string> AccNums()
{
  vector <string> vAccNums;
  short pos;
  
  for (const string &ln:LoadFromFile("Clients.txt")) {
    pos = ln.find("#-#");
    vAccNums.push_back(ln.substr(0, pos));
  }
	 
  return (vAccNums);
}

// Method to fetch a record with same (AccNum) inside the file then remove it if found!
