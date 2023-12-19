





#ifndef CommandModule_HPP
#define CommandModule_HPP



#include "Component.hpp"



class CommandModule : public Component {
protected :
   
public :   
   virtual bool HandleCommand(std::string arg);

   virtual void HandleEvent(EagleEvent e) override;

   virtual void Display(EagleGraphicsContext* win);

   virtual void Update(int timer_ticks);
};




#endif // CommandModule_HPP



