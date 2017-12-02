#include "../include/SpriteTextureManager.hpp"

namespace Corn
{
	void Sprite::loadTexture(string && nameOfFile, int scaleX, int scaleY, int posX, int posY)
	{
		if (!_textureObject.loadFromFile(nameOfFile))
		{ std::cout << "cannot find " << nameOfFile << std::endl; }

		_spriteObject.setTexture(_textureObject);
		_spriteObject.setPosition(posX, posY);
	}

	void Sprite::loadTexture(std::vector<Corn::Sprite> & obj, string && nameOfFile)
	{
		for(auto iterator = obj.begin(); iterator != obj.end(); ++iterator)
		{
			if (!iterator->_textureObject.loadFromFile(nameOfFile))
			{ std::cout << "cannot load " << nameOfFile << std::endl; }

			iterator->_spriteObject.setTexture(iterator->_textureObject);

			for(int elementScope = 0; elementScope <= obj.size(); ++elementScope)
			{
				obj[elementScope]._spriteObject.setPosition(X_POSITION * elementScope-60,0);
			}
		}
	}

	void Sprite::loadTexture(string && nameOfFile)
	{
		if (!_textureObject.loadFromFile(nameOfFile))
			{ std::cout << "cannot load " << nameOfFile << std::endl; }
		_spriteObject.setTexture(_textureObject);
		_spriteObject.setPosition(0,0);
	}
	
	void Sprite::updateObject(std::vector<Corn::Sprite> & sprObj)
	{
		int iterator = 0;

		for(auto index = _positionSpeed.begin(); index != _positionSpeed.end(); ++index)
		{
			*index = sprObj[iterator]._spriteObject.getPosition();

			if((index->x) >= X_POSITION)
			{
				sprObj[iterator]._spriteObject.setPosition(-543,0);
			}

			iterator++;

			if(iterator > 3)
			{
				iterator = 0;
			}
		}
	}

	void Sprite::moveObject(std::vector<Corn::Sprite> & obj, sf::Time & dt, const int & objSpeed)
	{
		for(auto index = obj.begin(); index != obj.end(); ++index)
		{
			index->_spriteObject.move(objSpeed * dt.asSeconds(),0);
		}
	}

	void Sprite::drawObject(std::vector<Corn::Sprite> & obj)
	{
		for(auto index = obj.begin(); index != obj.end(); ++index)
		{
			//Display::draw(index->_spriteObject);
		}
	}
}
