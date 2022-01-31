#include "solution.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace sol1257;
using namespace std;

/*takeaways
  - construct the tree top-down and store
    in the form of parent relationship
    in a map so later it can be traverse
    easily from child to parent
  - collect all the ancestors for region1
    in a set. The order doesn't matter
    as it's controlled by how we visit
    region2's ancestors
  - visit region2's ancestors bottom-up
    stop if we find a match. Since we
    are visiting bottom-up the match
    must be the smallest common region
*/

string Solution::scr(vector<vector<string>> &regions, string r1, string r2)
{
    unordered_map<string, string> parent;
    /*
       - we are pretty much building a tree
         top-down
       - only that we use a map to store the tree
         in the form of parent relationship as
         later we need to walk from the child
         to the parent while traversing the tree

    */
    for (const auto &region : regions)
    {
        for (int i = 1; i < region.size(); ++i)
        {
            /*
              - ["North America","United States","Canada"]
              - set United States and Canada's parent
                to North America
           */
            parent[region[i]] = region[0];
        }
    }

    unordered_set<string> ancestors;

    /*
      - walk up the tree to find all
        ancestors for region 1;
        you are traversing the tree
        all the way to the root
      - you need to include region 1
        as well as it might just be
        the parent of region 2
    */
    while (r1 != "")
    {
        ancestors.insert(r1);
        r1 = parent[r1];
    }

    /* C++ note
       - Because unordered_set containers do not allow for duplicate values,
         this means that the function actually returns 1 if an element with
         that value exists in the container, and zero otherwise.
    */

    /*
      - we traverse the tree bottom-up
      - so the first match we found will
        be the smallest common region
    */
    while (!ancestors.count(r2))
    {
        r2 = parent[r2];
    }

    return r2;
}