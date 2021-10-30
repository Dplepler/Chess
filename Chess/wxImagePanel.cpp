#include "wxImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_PAINT(wxImagePanel::paintEvent)
    EVT_LEFT_DOWN(wxImagePanel::mouseDown)
END_EVENT_TABLE()

wxImagePanel::wxImagePanel(wxFrame* parent, Board* board, Play* play) :
    wxPanel(parent) 
{
    this->window = parent;
    this->board = board;
    this->play = play;
}

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

void wxImagePanel::addImage(wxBitmap img, wxPoint coords)
{
    images.push_back(img);
    this->coords.push_back(coords);

}

void wxImagePanel::drawText(wxPoint coords, std::string message)
{
    wxClientDC dc(this);
    wxFont font(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
    dc.SetFont(font);
    dc.SetTextForeground(wxColour(255, 0, 0));
    dc.DrawText(message, coords.x, coords.y);
}

void wxImagePanel::mouseDown(wxMouseEvent& event)
{
    wxPoint pt = wxGetMousePosition();
    int fixedPointX = 0;
    int fixedPointY = 0;
    static wxDragImage* drag = nullptr;
    static Piece* piece = nullptr;

    int x = 0;
    int y = 0;

    // Fix position of getMousePosition function 
    fixedPointX = pt.x - 60;
    fixedPointY = pt.y - 65;
    //drawText(wxPoint(pt.x, pt.y), std::string(std::to_string(pt.x) + ", " + std::to_string(pt.y)));

    // Exit if mouse click was out of the border
    if (fixedPointX < 170 || fixedPointX > 170 + WIDTH)
        return;
    if (fixedPointY < 55 || fixedPointY > 55 + HEIGHT)
        return;

    x = ((fixedPointX - 170) - ((fixedPointX - 170) % 75)) / 75;
    y = ((fixedPointY - 55) - ((fixedPointY - 55) % 75)) / 75;

    if (this->play->selectOrMove == SELECT)
        piece = this->board->getPiece(y, x);

       
    if (!piece)
        return;

    if (this->play->selectOrMove == SELECT && !this->play->checkValidSrc(this->board, piece))
    {
       drawText(wxPoint(500, 55), std::string("You can't move the other player's piece\n"));
    }
    else if (this->play->selectOrMove == MOVE && !this->play->checkValidDest(this->board, piece, wxPoint(x, y)))
    {
        drawText(wxPoint(500, 55), std::string("You already have a piece at the desired position\n"));
    }
    else
    {
        if (this->play->selectOrMove == SELECT)
        {
            drag = new wxDragImage(piece->image);
            this->play->selectOrMove = MOVE;
        }
        else
        {
            this->play->makeMove(this->board, piece, wxPoint(x, y));
            drag->BeginDrag(wxPoint(piece->column * 75 + 170, piece->line * 75 + 55), this->window, false);
            drag->Move(wxPoint(pt.x, pt.y));
            drag->Show();
            drag->EndDrag();
        }
    }
    
}

