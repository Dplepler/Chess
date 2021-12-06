#ifndef CAPP_CLASS_H
#define CAPP_CLASS_H

#include "wx/wx.h"
#include "wx/bitmap.h"
#include "wxImagePanel.h"
#include "wx/sizer.h"

#include <iostream>

#define WIDTH 950
#define HEIGHT 739

#define UNIQUE_PIECE_AMOUNT 6

class cApp : public wxApp
{

public:
	cApp() = default;
	~cApp() = default;

	virtual bool OnInit();

private:

	wxFrame* m_frame1 = nullptr;
	wxImagePanel* drawPane;


};

#endif
