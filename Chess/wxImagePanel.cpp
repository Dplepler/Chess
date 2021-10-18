#include "wxImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_PAINT(wxImagePanel::paintEvent)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent) :
    wxPanel(parent) {}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void wxImagePanel::paintEvent(wxPaintEvent &evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void wxImagePanel::paintNow()
{
    // depending on your system you may need to look at double-buffered dcs
    wxClientDC dc(this);
    render(dc);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void wxImagePanel::render(wxDC &dc)
{
    unsigned int i = 0;
    size_t size = this->images.size();

    for (i = 0; i < size; i++)
    {
        dc.DrawBitmap(images[i], coords[i].x, coords[i].y, false);
    }
   
}

void wxImagePanel::addImage(wxImage* img, wxString file, wxBitmapType format, wxPoint coords)
{
    wxBitmap image = wxBitmap(*img);

    img->LoadFile(file, format);

    image = wxBitmap(*img);

    images.push_back(image);
    this->coords.push_back(coords);


}