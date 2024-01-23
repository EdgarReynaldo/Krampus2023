



#ifndef Intro_Scene_HPP
#define Intro_Scene_HPP

#include "Scene.hpp"



class Intro : public Scene {

protected :
public :
   Intro();

   virtual int Init() override;

   virtual void Display() override;
   virtual bool HandleEvent(EagleEvent e) override;
   virtual int Update(double dt) override;

};


#endif // Intro_Scene_HPP
