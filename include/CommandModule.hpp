





#ifndef CommandModule_HPP
#define CommandModule_HPP



class CommandModule : public Component {
protected :
   
   
   virtual bool HandleCommand(std::string arg);
   virtual bool HandleCommand(std::string arg) {
      
   }
   void HandleEvent(EagleEvent e) override;
void CommandModule::HandleEvent(EagleEvent e) {
   
}
   
   
public :
   
   
   
   
   
   bool operator()(std::string arg);
bool CommandModule::operator()(std::string arg) {
   return HandleCommand(arg);
}
};






#endif // CommandModule_HPP



