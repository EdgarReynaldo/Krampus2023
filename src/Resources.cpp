



#include "Resources.hpp"





Resource::Resource() :
      rt(NUM_RES_TYPES),
      val(0)
{}



Resource::Resource(RESTYPE restype , int value) : 
      rt(restype),
      val(value) 
{}



Resource Resource::operator-() {
   return Resource(rt , -val);
}



ResourceWallet::ResourceWallet() :
      rwallet()
{
   rwallet.resize(NUM_RES_TYPES , Resource());
   for (unsigned int i = 0 ; i < NUM_RES_TYPES ; ++i) {
      rwallet[i].rt = (RESTYPE)i;
   }
}



ResourceWallet::ResourceWallet(std::vector<int> values) :
      rwallet()
{
   rwallet.resize(NUM_RES_TYPES , Resource());
   for (unsigned int i = 0 ; i < NUM_RES_TYPES ; ++i) {
      rwallet[i].rt = (RESTYPE)i;
      rwallet[i].val = values[i];
   }
}



ResourceWallet& ResourceWallet::Acquire(Resource r) {
   rwallet[r.rt].val += r.val;
   return *this;
}



ResourceWallet& ResourceWallet::Spend(Resource r) {
   return Acquire(-r);
}



ResourceWallet& ResourceWallet::Trade(ResourceWallet& other , Resource ours , Resource theirs) {
   other.Spend(theirs).Acquire(ours);
   Spend(ours).Acquire(theirs);
   return *this;
}



int ResourceWallet::TotalValue() {
   int total = 0;
   for (unsigned int i = 0 ; i < NUM_RES_TYPES ; ++i) {
      total += rwallet[i].val;
   }
   return total;
}

