#pragma once
#include "IMenu.h"

using namespace std;

class MainMenu : public IMenu {
public:
	int ID = 4;
	MainMenu(Presenter* NewAppPresenter);
	~MainMenu();
	void ShowMenuBody();
	void UpdateBody();
	void SetStoreAndVendorInfo(string NewStoreName, string NewStoreAddress, string NewVendorFullName, string NewVendorID);
protected:
	void ProcessInputAction();
private:
	string StoreName;
	string StoreAddress;
	string VendorFullName;
	string VendorID;
};