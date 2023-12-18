





#ifndef CommandModule_HPP
#define CommandModule_HPP



#include "Component.hpp"



class CommandModule : public Component {
protected :
   
public :   
   virtual bool HandleCommand(std::string arg);
   virtual void HandleEvent(EagleEvent e) override;
   
public :
   
   
   
   bool operator()(std::string arg);
};

bool CommandModule::HandleCommand(std::string arg) {
   
}
void CommandModule::HandleEvent(EagleEvent e) {
   
}
bool CommandModule::operator()(std::string arg) {
   return HandleCommand(arg);
}





#endif // CommandModule_HPP



