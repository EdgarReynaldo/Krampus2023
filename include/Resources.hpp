



#ifndef GameResources_HPP
#define GameResources_HPP

#include <map>
#include <vector>
#include <string>


enum RESTYPE {
   RES_OXYGEN    = 0,
   RES_FOOD      = 1,
   RES_WATER     = 2,
   RES_ENERGY    = 3,
   RES_GOLD      = 4,
   RES_METAL     = 5,
   RES_MINERAL   = 6,
   NUM_RES_TYPES = 7
};



class Resource {
public :
   RESTYPE rt;
   int val;

   Resource();
   Resource(RESTYPE restype , int value);
   
   Resource operator-();
};



class ResourceWallet {
protected :
   std::vector<Resource> rwallet;
   
public :
   
   ResourceWallet();
   ResourceWallet(std::vector<int> values);

   ResourceWallet& Acquire(Resource r);
   ResourceWallet& Spend(Resource r);
   ResourceWallet& Trade(ResourceWallet& other , Resource ours , Resource theirs);

   int TotalValue();
};




#endif // GameResources_HPP







