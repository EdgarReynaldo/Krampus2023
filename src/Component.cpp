



#include "Component.hpp"
#include "Hexagon.hpp"


#include "Eagle/GraphicsContext.hpp"




Component::Component() :
      ourtile(0)
{}



void Component::HandleEvent(EagleEvent e) {
   (void)e;
}



void Component::Display(EagleGraphicsContext* win) {
   (void)win;
}



void Component::Update(int timer_ticks) {
   (void)timer_ticks;
}






