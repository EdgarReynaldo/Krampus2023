



#ifndef Game_Scene_HPP_PP
#define Game_Scene_HPP_PP


#include "Scene.hpp"
#include "Hexagon.hpp"



class GameScene : public Scene {
protected :
   HexGrid grid;
public :

   virtual int Init();
   virtual void Display();
   virtual bool HandleEvent(EagleEvent e);
   virtual int Update(double dt);
};



#endif // Game_Scene_HPP_PP

