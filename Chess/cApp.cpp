#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {}
cApp::~cApp() {}

bool cApp::OnInit()
{

	wxInitAllImageHandlers();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	m_frame1 = new wxFrame(NULL, wxID_ANY, wxT("Plepler Chess"), wxPoint(50, 50), wxSize(WIDTH, HEIGHT));

	drawPane = new wxImagePanel(m_frame1);
	
	drawPane->addImage(new wxImage(934, 700), "Images/chessBoard.png", wxBITMAP_TYPE_PNG, wxPoint(0, 0));
	drawPane->addImage(new wxImage(75, 75), "Images/King.png", wxBITMAP_TYPE_PNG, wxPoint(50, 50));

	sizer->Add(drawPane, 1, wxEXPAND);
	m_frame1->SetSizer(sizer);

	m_frame1->Show();


	return true;
}