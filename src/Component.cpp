



#include "Component.hpp"
#include "Eagle/GraphicsContext.hpp"
#include "Eagle/Events.hpp"





void Componenet::LogicTick() {
   logic_count++;
   if (logic_count >= ticks_per_upkeep) {
      logic_count -= ticks_per_upkeep;
      upkeep_count++;
   }
}




void Component::HandleEvent(EagleEvent e) {
   (void)e;
}



void Component::Display(EagleGraphicsContext* win) {
   (void)win;
}



void Component::Update(int timer_ticks) {
   while (timer_ticks > 0) {
      LogicTick();
      --timer_ticks;
   }
}






