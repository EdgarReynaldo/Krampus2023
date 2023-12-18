



#ifndef Component_HPP
#define Component_HPP





class Component {

   int logic_count;
   int ticks_per_upkeep;

   ResourceTracker income_per_turn;
   ResourceTracker cost_per_turn;

   virtual void LogicTick();
void Componenet::LogicTick() {
   logic_count++;
   if (logic_count >= ticks_per_upkeep) {
      logic_count -= ticks_per_upkeep;
      
   }
   
}
   
public :
   
//   Component();
Component() :
      logic_count(0),
      ticks_per_upkeep(600),
      income(),
      cost()
{}   
   
   virtual ~Component() {}
   

   virtual void HandleEvent(EagleEvent e);

   virtual void Display(EagleGraphicsContext* win);

   virtual void Update(int timer_ticks);

};

#endif // Component_HPP
