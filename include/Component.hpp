



#ifndef Component_HPP
#define Component_HPP


#include "Resources.hpp"


#include "Eagle/Events.hpp"

class EagleGraphicsContext;



class Component {
   
public :
   
//   Component();
Component() {}
   
   virtual ~Component() {}
   
   virtual void HandleEvent(EagleEvent e);

   virtual void Display(EagleGraphicsContext* win);

   virtual void Update(int timer_ticks);

   virtual ResourceWallet IncomePerTurn()=0;
   virtual ResourceWallet CostPerTurn()=0;
};

#endif // Component_HPP
