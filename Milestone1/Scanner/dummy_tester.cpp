#include "types.h"

int main()
{
  Token tk(ID,1);
  std::cout << tk.to_string()<<std::endl;
}
