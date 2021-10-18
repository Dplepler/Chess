#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {}
cApp::~cApp() {}

bool cApp::OnInit()
{
	unsigned int i = 0;
	std::string str;
	wxImage* image;

	wxInitAllImageHandlers();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	m_frame1 = new wxFrame(NULL, wxID_ANY, wxT("Plepler Chess"), wxPoint(50, 50), wxSize(WIDTH, HEIGHT));

	drawPane = new wxImagePanel(m_frame1);
	
	drawPane->addImage(new wxImage(934, 700), "Images/chessBoard.png", wxBITMAP_TYPE_PNG, wxPoint(0, 0));

	for (i = 0; i < UNIQUE_PIECE_AMOUNT; i++)
	{
		image = new wxImage(100, 100);
		str = "Images/" + std::to_string(i) + ".png";
		drawPane->addImage(image, str, wxBITMAP_TYPE_PNG, wxPoint(i * 75 + 175, 55));
	}
	

	sizer->Add(drawPane, 1, wxEXPAND);
	m_frame1->SetSizer(sizer);

	m_frame1->Show();


	return true;
}