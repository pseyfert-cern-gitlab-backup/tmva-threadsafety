#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace safe
{
#include "./safe/TMVA_MLP_Forward1stLoop.h"
}
namespace reference
{
#include "./reference/TMVA_MLP_Forward1stLoop.h"
}

int main()
{
  std::array<float, 7> l0;
  safe::ReadMLP_Forward1stLoop* saf =
    new safe::ReadMLP_Forward1stLoop( {"nPlanes", "dSlope", "dp", "slope2", "dby", "dbx", "day"} );
  reference::ReadMLP_Forward1stLoop* ref =
    new reference::ReadMLP_Forward1stLoop( {"nPlanes", "dSlope", "dp", "slope2", "dby", "dbx", "day"} );
  std::vector<float> input;
  input.insert( input.begin(), l0.begin(), l0.end() );
  float refval = ref->GetMvaValue( input );
  float safval = saf->GetMvaValue( input );
  std::cout << "reference = " << refval << "\t\tsafe value = " << safval << std::endl;


return 0;
}
