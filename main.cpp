#include <iostream>
#include "solution.h"

using namespace std;
using namespace sol1257;

/*
  Input:
  regions =
  [["Earth","North America","South America"],
  ["North America","United States","Canada"],
  ["United States","New York","Boston"],
  ["Canada","Ontario","Quebec"],
  ["South America","Brazil"]],
  region1 = "Quebec",
  region2 = "New York"
  Output: "North America"
*/

vector<vector<string>> testFixture1()
{
  return {{"Earth", "North America", "South America"},
          {"North America", "United States", "Canada"},
          {"United States", "New York", "Boston"},
          {"Canada", "Ontario", "Quebec"},
          {"South America", "Brazil"}};
}

void test1()
{
  auto fixture = testFixture1();
  Solution sol;

  cout << "Test 1 - expect to see North America" << endl;
  cout << "result: " << sol.scr(fixture, "Quebec", "New York") << endl;
}

main()
{
  test1();
}