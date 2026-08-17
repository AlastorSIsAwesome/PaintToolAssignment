#pragma once

#include <Windows.h>
#include <ShObjIdl.h>
#include <string>
#include "cButton.h"

class cFileInterface
{
private:
protected:
public:
	cFileInterface();
	~cFileInterface();

	void LoadFile(sf::RenderTexture* _texture);
	void SaveFile(sf::RenderTexture* _texture); // doesnt have to be bool bc sfml is cool like that and will just say if something is up

};

