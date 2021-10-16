#ifndef CAPP_CLASS_H
#define CAPP_CLASS_H

#include "wx/wx.h"
#include "main.h"


class cApp : public wxApp
{

public:
	cApp();
	~cApp();

	virtual bool onInit();

private:
	Main* m_frame1 = nullptr;

};

#endif
