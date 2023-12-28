



#include "CommandModule.hpp"




void CommandModule::HandleEvent(EagleEvent e) {
   (void)e;
}



void CommandModule::Display(EagleGraphicsContext* win) {
   (void)win;
}



void CommandModule::Update(int timer_ticks) {
   (void)timer_ticks;
   
}



ResourceWallet CommandModule::IncomePerTurn() {
   static const ResourceWallet rw({10 , 50 , 50 , 60 , 100 , 30 , 30});
   return rw;
}



ResourceWallet CommandModule::CostPerTurn() {
   static const ResourceWallet rw;
   return rw;
}







