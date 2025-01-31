#ifndef USER_HANDLER
#define USER_HANDLER

#include "core.hpp"

stUsers LineToRec(vector <string> Line);
stUsers FetchUsername(string Username);
//stUsers GetUsername(string Username);
bool AuthenticateUser();

#endif /* USER_HANDLER */
