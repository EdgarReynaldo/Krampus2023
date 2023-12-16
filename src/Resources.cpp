



#include "Resources.hpp"



ResourceTracker::ResourceTracker() :
      resmap()
{
   for (int r = 0 ; r < NUM_RES_TYPES ; ++r) {
      std::vector<Resource>& res = resmap[(RESTYPE)r];
      for (unsigned int ql = 0 ; ql < 10 ; ++ql) {
         res.push_back(Resource(0,ql,(RESTYPE)r));
      }
   }
}
   


void ResourceTracker::Acquire(Resource r) {
   std::vector<Resource>& res = resmap[r.restype];
   res[r.quality].quantity += r.quantity;
}



Resource ResourceTracker::Release(Resource r) {
   std::vector<Resource>& res = resmap[r.restype];
   Resource& ours = res[r.quality];
   /// They get what they asked for
   Resource ret = r;
   ours.quantity -= r.quantity;/// This may put us in negative
   if (ours.quantity < 0) {
      BalanceValue(*this , r.restype);
   }
   return ret;
}



void ResourceTracker::Trade(ResourceTracker& other , Resource ours , Resource theirs) {
   other.Acquire(Release(ours));
   other.Release(theirs);
   Acquire(theirs);
}



void ResourceTracker::BalanceValue(ResourceTracker& rt , RESTYPE rtype) {
//   int total = ResourceTracker::TotalValue(rt,rtype);
   /// check for negative quantities
   int base = 1;
   int base2 = 1;
   Resource* res1 = 0;
   Resource* res2 = 0;
   int value1 = 0;
   int value2 = 0;
   std::vector<Resource>& resvec = rt.resmap[rtype];
   for (unsigned int index = 0 ; index < 9 ; ++index) {
      res1 = &resvec[index];
      res2 = &resvec[index + 1];
      
      value1 = res1->quantity*base;
      if (res1->quantity > 9) {
         ///Need to carry to higher quality
         int rem = res1->quantity%10;
         res2->quantity += res1->quantity/10;
         res1->quantity = rem;
      }
      else if (res1->quantity < 0) {
         /// Need to borrow from higher quality
         base2 = base*10;
         for (unsigned int index2 = index + 1 ; index2 < 10 ; ++index2) {
            res2 = &resvec[index2];
            value2 = res2->quantity*base2;
            value1 += value2;
            value2 = 0;
            res2->quantity = 0;
            res1->quantity = value1/base;
            if (base > 1) {
               resvec[base - 1].quantity += value1%base;
            }
            base2 *= 10;
         }
      }
   
      base *= 10;
   }
}



int ResourceTracker::TotalValue(ResourceTracker& rt , RESTYPE rtype) {
   int total = 0;
   int base = 1;
   const std::vector<Resource>& resvec = rt.resmap[rtype];
   for (unsigned int i = 0 ; i < 10 ; ++i) {
      total += base*resvec[i].quantity;
      base *= 10;
   }
   return total;
}








