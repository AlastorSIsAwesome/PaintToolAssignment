/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cFileInterface.h]
Description : [Blueprint for files being loaded into the program]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

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

	void LoadFile(sf::RenderTexture* _texture);// doesnt have to be bool bc sfml is cool like that and will just say if something is up
	void SaveFile(sf::RenderTexture* _texture); 

};