#ifndef HANDLERS_H
#define HANDLERS_H

#include "core.hpp"

string ReadInputs(const char *Msg);
stClients RecordClientData();


//Helpers
string RecToLine(stClients Cl, string DELIM);
vector <string> AccNums();
vector <string> VerifyAccNums(string fname);
string LineFilter(string Record);
uint16_t ClientsCounter();
 
//File Manager
void SaveRecToFile(vector <string> &vClients, string fname);
vector <string> LoadFromFile(string fname);
void SaveSingleRecToFile(string Line, string fname);

//Crud Ops
void InsertClients();
#endif /*HANDLERS_H*/
