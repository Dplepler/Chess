#ifndef WX_IMAGE_PANEL_CLASS_H
#define WX_IMAGE_PANEL_CLASS_H

#include "wx/wx.h"
#include "wx/dragimag.h"
#include "play.h"
#include <vector>


#define WIDTH 950
#define HEIGHT 739

class wxImagePanel : public wxPanel
{


public:

    std::vector<wxBitmap> images;
    std::vector<wxPoint> coords;

    Board* board;
    Play* play;
    

    wxImagePanel(wxFrame* parent, Board* board, Play* play);
    int searchImage(wxBitmap img);

    void addImage(wxBitmap img, wxPoint coord);
    
    void paintEvent(wxPaintEvent &evt);

    void drawText(wxPoint coords, std::string message);
    void paintNow();

    void render(wxDC &dc);

    void mouseDown(wxMouseEvent& event);
    DECLARE_EVENT_TABLE()

private:
    wxWindow* window;

    
};


#endif
