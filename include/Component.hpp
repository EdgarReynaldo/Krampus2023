



#ifndef Component_HPP
#define Component_HPP


#include "Resources.hpp"


#include "Eagle/Events.hpp"

class EagleGraphicsContext;



class Component {

   int logic_count;
   int ticks_per_upkeep;
   int upkeep_count;

   ResourceTracker income_per_turn;
   ResourceTracker cost_per_turn;

   virtual void LogicTick();
   
public :
   
//   Component();
Component() :
      logic_count(0),
      ticks_per_upkeep(600),
      upkeep_count(0),
      income_per_turn(),
      cost_per_turn()
{}
   
   virtual ~Component() {}
   

   virtual void HandleEvent(EagleEvent e);

   virtual void Display(EagleGraphicsContext* win);

   virtual void Update(int timer_ticks);

};

#endif // Component_HPP
