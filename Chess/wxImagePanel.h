#ifndef WX_IMAGE_PANEL_CLASS_H
#define WX_IMAGE_PANEL_CLASS_H

#include "wx/wx.h"
#include <vector>

class wxImagePanel : public wxPanel
{
    
public:

    std::vector<wxBitmap> images;
    std::vector<wxPoint> coords;

    wxImagePanel(wxFrame* parent);
    void addImage(wxBitmap img, wxPoint coords);

    void paintEvent(wxPaintEvent &evt);

    void paintNow();

    void render(wxDC &dc);

    /*
     void mouseMoved(wxMouseEvent& event);
     
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */

    void mouseDown(wxMouseEvent& event);

    DECLARE_EVENT_TABLE()
};


#endif
