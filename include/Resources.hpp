



#ifndef Resources_HPP
#define Resources_HPP

#include <map>
#include <vector>
#include <string>


enum RESTYPE {
   RES_OXYGEN = 0,
   RES_FOOD   = 1,
   RES_ENERGY = 2,
   RES_GOLD   = 3,
   RES_METAL  = 4,
   RES_MINERAL= 5,
   NUM_RES_TYPES = 6
};



class Resource {
public :
   RESTYPE restype;
   int quantity;
   int quality;/// Multiply by 10^quality to get value, from 0-9
   Resource(int qnt , int qlt , RESTYPE rt) : restype(rt) , quantity(qnt) , quality(qlt) {}
};

class ResourceTracker {
protected :
   
   std::map<RESTYPE , std::vector<Resource> > resmap;
   
public :
   
   ResourceTracker();
   

   void Acquire(Resource r);

   Resource Release(Resource r);

   void Trade(ResourceTracker& other , Resource ours , Resource theirs);


   static void BalanceValue(ResourceTracker& r , RESTYPE rtype);
   static int TotalValue(ResourceTracker& rt , RESTYPE rtype);
};





#endif // Resources_HPP







