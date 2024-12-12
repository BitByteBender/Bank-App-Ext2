#include "headers/displayLib.hpp"
#include "headers/core.hpp"

using displayLib::DisplayMenuWrapper;

int main(void)
{
  DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client", true);
  DisplayTable("-", 90, false);
  return (0);
}
