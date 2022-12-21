#include<iostream>
#include "../Menus/IMenu.h"
#include "../Menus/MainMenu.h"
#include "../Menus//HistorialMenu.h"
#include "../Menus/CotizarMenu.h"
#include "../Menus/StepsMenu.h"
#include "../Presenter/Presenter.h"
#include "View.h"

using namespace std;

View::View() {
	PresenterUP = std::make_unique<Presenter>();
	PresenterPtr = PresenterUP.get();
}

View::~View() {
	cout << "View Destructor" << endl;
}

void View::RenderApp() {
	RenderMenu(EMenu::Main);
}

void View::RenderMenu(EMenu NewMenu) {
	switch (NewMenu) {
		case EMenu::Main:
			CurrentMenuUP = std::make_unique<MainMenu>(this);
			CurrentMenuPtr = CurrentMenuUP.get();
		break;
		case EMenu::History:
			CurrentMenuUP = std::make_unique<HistorialMenu>(this);
			CurrentMenuPtr = CurrentMenuUP.get();
		break;
		case EMenu::Cotizar:
			CurrentMenuUP = std::make_unique<CotizarMenu>(this);
			CurrentMenuPtr = CurrentMenuUP.get();
		break;
		case EMenu::Steps:
			CurrentMenuUP = std::make_unique<StepsMenu>(this);
			CurrentMenuPtr = CurrentMenuUP.get();
		break;
		case EMenu::Price:
			CurrentMenuUP = std::make_unique<StepsMenu>(this);
			CurrentMenuPtr = CurrentMenuUP.get();
		break;
	}
	std::system("CLS");
	CurrentMenuPtr->ShowMenu();
}

void View::SetNewPrenda(EPrendaType NewPrendaType) {
	PresenterPtr->SetNewPrenda(NewPrendaType);
}

std::vector<SPrendaChoice> View::GetCotizacionSteps() {
	return PresenterPtr->GetCotizacionSteps();
}

void View::AddPropertyToCurrentPrenda(EPrendaType PrendaProperty) {
	PresenterPtr->AddPropertyToCurrentPrenda(PrendaProperty);
}

void View::SetPriceToCurrentPrenda(int NewPrice) {
	PresenterPtr->SetPriceToCurrentPrenda(NewPrice);
}

void View::NewHistoryRecord() {
	PresenterPtr->NewHistoryRecord();
}