#ifndef SPRITETEXTUREMANAGER_HPP
#define SPRITETEXTUREMANAGER_HPP

#include <stdio.h>
#include <string>
using std::string;
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;

namespace Corn
{
	class Sprite
	{
	public:
		Sprite()
		{
			int ELEMENT_SIZE = 2;
			_positionSpeed.resize(ELEMENT_SIZE);
		}

		void loadTexture(string &&, int, int, int, int);
		void loadTexture(std::vector<Corn::Sprite> &, string &&);
		void loadTexture(string &&);
		
		void setPosition(int);
		void updateObject(std::vector<Corn::Sprite> &);
		void setPositionObj(std::vector<Corn::Sprite>&,const int &);
		void moveObject(std::vector<Corn::Sprite> &, sf::Time &, const int &);
		void drawObject(std::vector<Corn::Sprite> &);

		sf::Sprite _spriteObject;
		sf::Texture _textureObject;

		const int X_POSITION = 272;
		const int Y_POSITION = 160;

	private:
		std::vector<sf::Vector2f> _positionSpeed;
	};
}

#endif // SPRITETEXTUREMANAGER_HPP