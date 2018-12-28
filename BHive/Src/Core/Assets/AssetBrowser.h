#ifndef ASSETBROWSER_H
#define ASSETBROWSER_H

#include "Asset.h"
#include "Core/Log/Log.h"

class AssetBrowser
{
public:
	AssetBrowser();
	~AssetBrowser();

	void LoadAssetsFromFolder(std::string path);

	void RefreshBrowser();

	void AddNewAsset(std::string path);

	void DeleteAsset(Asset* asset);

private:
	std::vector<std::unique_ptr<Asset>> LoadedAssets;
};

#endif