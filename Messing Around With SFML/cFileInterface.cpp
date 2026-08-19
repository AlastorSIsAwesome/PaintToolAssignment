/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [cFileInterface.cpp]
Description : [Implimentation of importing files into the RenderTexture]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#include "cFileInterface.h"

cFileInterface::cFileInterface()
{
}

cFileInterface::~cFileInterface()
{
}

void cFileInterface::LoadFile(sf::RenderTexture* _texture)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;

		//here we create ofd
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog,
			reinterpret_cast<void**>(&pFileOpen));

		// filters for types
		LPCWSTR szJPG = L"Jpeg";
		LPCWSTR szBMP = L"Bitmap";
		LPCWSTR szALL = L"All"; // L tells compiler to make the decision on how to convert it

		COMDLG_FILTERSPEC rgSpec[] =
		{
			{szALL, L"*.*"},
			{szJPG, L"*.jpg;*.jpeg"},
			{szBMP, L"*.bmp"}
		};

		pFileOpen->SetFileTypes(3, rgSpec);

		if (SUCCEEDED(hr))
		{
			hr = pFileOpen->Show(NULL);

			if (SUCCEEDED(hr))
			{
				// get name of file
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);

				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					if (SUCCEEDED(hr))
					{
						sf::Texture newTex(pszFilePath);
						sf::Sprite newSprite(newTex);

						_texture->draw(newSprite);
						_texture->display();

						MessageBoxW(NULL, L"Image loaded Successfuly!", L"Success!", MB_OK);
						CoTaskMemFree(pszFilePath);

					}

					pItem->Release();
				}
			}

			pFileOpen->Release();
		}

		CoUninitialize();
	}
}

void cFileInterface::SaveFile(sf::RenderTexture* _texture)
{
}
