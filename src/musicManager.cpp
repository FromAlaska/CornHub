#include "../include/musicManager.hpp"
#include <string>

MusicManager::MusicManager(){
	if(!music_.setMusicBuffer("../resources/sounds/bgSound.wav"))
		std::cout <<"failed to load background music." << std::endl;
	else()
	{
		music_.play();
	}

}

void MusicManager::loadBuffer()
{
}
void MusicManager::setSoundBuffer(const std::string & pathToSoundFile){
	pathToSoundFile_ = pathToSoundFile;
}
void MusicManager::setMusicBuffer(const std::string & pathToMusicFile){
	pathMusicFile_=pathMusicFile;
}
void MusicManager::playMusic(){}
void MusicManager::playSFX(MusicManager::SFX soundFX){}