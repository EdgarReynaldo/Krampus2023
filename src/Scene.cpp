



#include "Scene.hpp"



Scene::Scene() :
      elapsed(0.0)
{}



int Scene::Init() {
   return SCENE_READY;
}



void Scene::Display() {
   (void)0;
}



bool Scene::HandleEvent(EagleEvent e) {
   (void)e;
   return false;
}



int Scene::Update(double dt) {
   elapsed += dt;
   return SCENE_RUNNING;
}



