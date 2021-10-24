#include "cApp.h"
#include "board.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {}
cApp::~cApp() {}

bool cApp::OnInit()
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	size_t size = 0;
	std::string str;
	wxImage* img = new wxImage(WIDTH, HEIGHT);
	wxBitmap image;

	wxInitAllImageHandlers();

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	m_frame1 = new wxFrame(NULL, wxID_ANY, wxT("Plepler Chess"), wxPoint(50, 50), wxSize(WIDTH, HEIGHT));

	drawPane = new wxImagePanel(m_frame1);

	img->LoadFile("Images/chessBoard.png", wxBITMAP_TYPE_PNG);
	image = wxBitmap(*img);

	drawPane->addImage(image, wxPoint(0, 0));

	Board* board = new Board();

	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			if (board->board[i][i2])
			{
				int x = board->board[i][i2]->column * 75 + 168;
				int y = board->board[i][i2]->line * 75 + 55;

				drawPane->addImage(board->board[i][i2]->image, wxPoint(x, y));

			}
			
		}
		
	}


	sizer->Add(drawPane, 1, wxEXPAND);
	m_frame1->SetSizer(sizer);

	m_frame1->Show();


	return true;
}