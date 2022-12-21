#pragma once
#include<memory>
#include<vector>

class Presenter;
class IMenu;
enum class EMenu;
enum class EPrendaType;
struct SPrendaChoice;

class View {
public:
	View();
	~View();
	void RenderApp();
	void RenderMenu(EMenu NewMenu);
	void SetNewPrenda(EPrendaType NewPrendaType);
	std::vector<SPrendaChoice> GetCotizacionSteps();
	void AddPropertyToCurrentPrenda(EPrendaType PrendaProperty);
	void SetPriceToCurrentPrenda(int NewPrice);
	void NewHistoryRecord();
private:
	std::unique_ptr<Presenter> PresenterUP;
	Presenter* PresenterPtr;
	std::unique_ptr<IMenu> CurrentMenuUP;
	IMenu* CurrentMenuPtr;
};