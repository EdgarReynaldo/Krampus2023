





#ifndef CommandModule_HPP
#define CommandModule_HPP


#include "Eagle/Events.hpp"
#include "Component.hpp"

#include <string>

class CommandModule : public Component {
protected :
   
public :   
   virtual void HandleEvent(EagleEvent e) override;

   virtual void Display(EagleGraphicsContext* win) override;

   virtual void Update(int timer_ticks) override;
};




#endif // CommandModule_HPP



