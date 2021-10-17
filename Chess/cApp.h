#ifndef CAPP_CLASS_H
#define CAPP_CLASS_H

#include "wx/wx.h"
#include "wx/bitmap.h"
#include "wxImagePanel.h"
#include "wx/sizer.h"

#define WIDTH 950
#define HEIGHT 739


class cApp : public wxApp
{

public:
	cApp();
	~cApp();

	virtual bool OnInit();

private:

	wxFrame* m_frame1 = nullptr;
	wxImagePanel* drawPane;


};

#endif
