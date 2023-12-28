



#ifndef CommandModule_HPP
#define CommandModule_HPP


#include "Resources.hpp"
#include "Component.hpp"

#include <unordered_set>



class CommandModule : public Component {
protected :
   std::unordered_set<Component*> comp_set;

   ResourceWallet storage;
   
public :
//   CommandModule();   
//CommandModule::CommandModule() :
CommandModule() :
      comp_set(),
      storage()
{}
   virtual ~CommandModule() {}
   
   virtual void HandleEvent(EagleEvent e);

   virtual void Display(EagleGraphicsContext* win);

   virtual void Update(int timer_ticks);

   virtual ResourceWallet IncomePerTurn() override;
   virtual ResourceWallet CostPerTurn() override;
};




#endif // CommandModule_HPP



