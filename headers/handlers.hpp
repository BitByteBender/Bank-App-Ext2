#ifndef HANDLERS_H
#define HANDLERS_H

#include "core.hpp"

string ReadInputs(const char *Msg);
stClients RecordClientData(bool Trigger);
stUsers RecUsrData();

//Helpers [clients]
string RecToLine(stClients Cl, string DELIM);
vector <string> AccNums(string fname);
vector <string> VerifyAccNums(string fname);
string LineFilter(string Record);
uint16_t RecCounter(vector <string> &vRec);
vector <string> RecsToLines(vector <stClients> &vClients);

//Helpers [trxs]
string TrxLines(stClients Cl, string Amount, string DELIM);

//Helpers [users]
string RecToLine(stUsers Usr, string DELIM);

//File Manager
void SaveRecToFile(vector <string> &vClients, string fname);
vector <string> LoadFromFile(string fname);
void SaveSingleRecToFile(string Line, string fname);

//Crud Ops
void InsertClients();
void UpdateClient();
short FindClient(string AccNum, short Blocker);
void DeleteClient();
void DepositToAccount();
void WithdrawFromAccount();
#endif /*HANDLERS_H*/
