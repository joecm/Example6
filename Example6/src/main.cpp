/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/16 21:56:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Antonio Costa de Moya (), joseantonio.costa250@gmail.com
 *   Organization:  cosmobros.net.org
 *
 * =====================================================================================
 */

#include "ExampleApplication.h"
#include <iostream>

class SimpleExample : public ExampleApplication {
  public :
	void createScene() {
		mSceneMgr->setAmbientLight(Ogre::ColourValue(1, 1, 1));
		Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity", "Sinbad.mesh");
		Ogre::SceneNode *node = mSceneMgr->createSceneNode("Node1");
		node->setPosition(10,10,0);
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntity2", "ninja.mesh");
		Ogre::SceneNode* node2=node->createChildSceneNode("Node2", Ogre::Vector3(10,0,0));
		node2->setScale(0.02f,0.02f,0.02f);
		node2->attachObject(ent2);

		node->setPosition(40,10,0);
		node->yaw(Ogre::Degree(180.f));

		std::cout << "Posición Nodo 1:" << node->_getDerivedPosition() << std::endl;
		std::cout << "Posicion Nodo 2:" << node2->_getDerivedPosition() << std::endl;
    }
};

int main(void)  {
  SimpleExample example;
  example.go();

  return 0;
}


