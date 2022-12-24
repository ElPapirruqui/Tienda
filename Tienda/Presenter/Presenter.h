#pragma once
#include<memory>
#include<vector>
#include<string>

using namespace std;

class IMenu;
class Vendedor;
class Store;
class PrendaFactory;
enum class EMenu;
enum class EPrendaType;
struct SPrendaChoice;
struct SHistoryData;

class Presenter {
public:
	Presenter();
	~Presenter();
	SPrendaChoice* GetNextStep(int NextStep);
	void Start();
	void RenderMenu(EMenu NewMenu);
	void RenderMainMenu();
	void RenderStepsMenu();
	void RenderHistoryMenu(SHistoryData& History);
	void RenderHistoryMenu(vector<SHistoryData>& History);
	void SetNewPrenda(EPrendaType NewPrendaType);
	void AddPropertyToCurrentPrenda(EPrendaType PrendaProperty);
	void SetPriceToCurrentPrenda(int NewPrice);
	bool SetQuantityToCurrentPrenda(int NewQuantity);
	void NewHistoryRecord();
	void ShowHistoryRecords();
	void ProcessStepChoice(int MenuOption, SPrendaChoice* Step);
private:
	void UpdateStepBody(int NextStep);
	string CurrentDateTime();
	unique_ptr<Store> StoreUP;
	Store* StorePtr;
	unique_ptr<PrendaFactory> PrendaFactoryUP;
	PrendaFactory* PrendaFactoryPtr;	
	unique_ptr<IMenu> CurrentMenuUP;
	IMenu* CurrentMenuPtr;
	template <class _Ty>
	void CreateMenu();
};