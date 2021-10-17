#ifndef WX_IMAGE_PANEL_CLASS_H
#define WX_IMAGE_PANEL_CLASS_H

#include "wx/wx.h"
#include <vector>

class wxImagePanel : public wxPanel
{
    std::vector<wxBitmap> images;

public:
    wxImagePanel(wxFrame* parent);
    void addImage(wxImage* img, wxString file, wxBitmapType format);

    void paintEvent(wxPaintEvent &evt);

    void paintNow();

    void render(wxDC &dc);

    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */

    DECLARE_EVENT_TABLE()
};


#endif
