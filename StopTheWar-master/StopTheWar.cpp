
#include "SFML/Graphics.hpp"
#include "GameControllers/define.h"
#include "GameControllers/ResourcesManager.h"
#include "Scenes/GameScene.h"
#include "Scenes/MenuScene.h"
#include "GameControllers/Animation.h"
#include "GameControllers/SoundManager.h"
int main()
{

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Stop The WAR");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(LIMIT_FPS);

	ResourcesManager::getInstance()->LoadResource();
	SoundManager::getInstance()->LoadSoundResources();
	Scene *test;
	test = new MenuScene(SCREEN_WIDTH,SCREEN_HEIGHT);
	test->Init();
	SceneManager::GetInstance()->ReplaceScene(test);

	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		//	if (event.type == sf::Event::MouseMoved)
				
			//	SceneManager::GetInstance()->GetCurrentScene()->Event(event);
			if (event.type == sf::Event::MouseButtonPressed)
	
				SceneManager::GetInstance()->GetCurrentScene()->Event(event,window);

			if (event.type == sf::Event::KeyPressed||event.type == sf::Event::KeyReleased)
			{
				SceneManager::GetInstance()->GetCurrentScene()->Event(event,window);
			}

		}
		SceneManager::GetInstance()->Update(1.0 / LIMIT_FPS);

		window.clear(sf::Color(0, 200, 255, 0));

		SceneManager::GetInstance()->Render(window);

		window.display();
	}
	
		

	return 0;
}
