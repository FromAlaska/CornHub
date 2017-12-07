#ifndef MUSIC_MANAGER
#define MUSIC_MANAGER
#include <SFML/Audio.hpp>
#include <string>
class MusicManager{
public:
	enum SFX{EAT, SWITCH, WIN};
MusicManager();

void loadBuffer();
void setSoundBuffer(const std::string & pathToSoundFile);
void setMusicBuffer(const std::string & pathToMusicFile);
void playMusic();
void playSFX(SFX soundFX);

private:
sf::SoundBuffer buffer_;
sf::Music music_;
const std::string pathToSoundFile_;
const std::string pathToMusicFile_;

};
#endif