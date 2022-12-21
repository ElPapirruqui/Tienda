#pragma once
#include<memory>
#include<vector>

using namespace std;

class Presenter;
class IMenu;
enum class EMenu;
enum class EPrendaType;
struct SPrendaChoice;
struct SHistoryData;

class View {
public:
	View();
	~View();
	void RenderApp();
	void RenderMenu(EMenu NewMenu);
	void RenderHistoryMenu(SHistoryData& History);
	void RenderHistoryMenu(vector<SHistoryData>& History);
	void SetNewPrenda(EPrendaType NewPrendaType);
	vector<SPrendaChoice> GetCotizacionSteps();
	SPrendaChoice GetNextStep(int NextStep);
	void AddPropertyToCurrentPrenda(EPrendaType PrendaProperty);
	void SetPriceToCurrentPrenda(int NewPrice);
	bool SetQuantityToCurrentPrenda(int NewQuantity);
	void NewHistoryRecord();
private:
	unique_ptr<Presenter> PresenterUP;
	Presenter* PresenterPtr;
	unique_ptr<IMenu> CurrentMenuUP;
	IMenu* CurrentMenuPtr;
};