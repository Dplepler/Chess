#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {}
cApp::~cApp() {}

bool cApp::OnInit()
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	int x = 0;
	int y = 0;

	size_t size = 0;
	std::string str;
	wxImage* img = new wxImage(WIDTH, HEIGHT);
	wxBitmap* image;

	wxInitAllImageHandlers();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	m_frame1 = new wxFrame(NULL, wxID_ANY, wxT("Plepler Chess"), wxPoint(50, 50), wxSize(WIDTH, HEIGHT));

	Play* play = new Play();
	Board* board = new Board(play);

	drawPane = new wxImagePanel(m_frame1, board, play);

	img->LoadFile("Images/Chess.png", wxBITMAP_TYPE_PNG);
	image = new wxBitmap(*img);
	
	drawPane->addImage(image, wxPoint(0, 0));

	img->LoadFile("Images/Board.png", wxBITMAP_TYPE_PNG);
	image = new wxBitmap(*img);
	drawPane->addImage(image, wxPoint(170, 55));

	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			if (!board->getBoard()[i][i2])
				continue;
			
			x = board->getBoard()[i][i2]->getColumn() * 75 + 170;
			y = board->getBoard()[i][i2]->getLine() * 75 + 55;

			drawPane->addImage(board->getBoard()[i][i2]->getImage(), wxPoint(x, y));

			
			
		}
		
	}

	sizer->Add(drawPane, 1, wxEXPAND);
	m_frame1->SetSizer(sizer);

	m_frame1->Show();


	return true;
}