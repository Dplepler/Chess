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
        dc.DrawBitmap(*images[i], coords[i].x, coords[i].y, false);
    }
   
}

void wxImagePanel::addImage(wxBitmap* img, wxPoint coords)
{
    this->images.push_back(img);
    this->coords.push_back(coords);

}

int wxImagePanel::searchImage(wxBitmap* img)
{
    size_t size = this->coords.size();
    unsigned int i = 0;
    int index = -1;

    for (i = 0; i < size && index == -1; i++)
    {
        if (this->images[i] == img)
        {
            index = i;
        }
    }
        
    return index;
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
    pt = this->window->ScreenToClient(pt);  // Move the mouse position to become relative to the window

    unsigned int i = 0;

    int moveX = 0;
    int moveY = 0;
    static Piece* piece = nullptr;
    Piece* prevPiece = nullptr;

    std::vector<wxPoint>::iterator prevIndexIt;
    std::vector<wxBitmap*>::iterator prevBitmapIt;

    std::string error;

    int index = 0;
    int prevIndex = 0;

    int x = 0;
    int y = 0;

    x = ((pt.x - 170) - ((pt.x - 170) % 75)) / 75;
    y = ((pt.y - 55) - ((pt.y - 55) % 75)) / 75;
    

    if (x >= BOARD_WIDTH || y >= BOARD_HEIGHT)
        return;
    if (x < 0 || y < 0)
        return;
   

    if (this->play->selectOrMove == SELECT)
        piece = this->board->getPiece(y, x);

    if (!piece)
        return;

    if (this->play->selectOrMove == SELECT && !this->play->checkValidSrc(this->board, piece))
    {
       drawText(wxPoint(500, 55), std::string("You can't move the other player's piece\n"));
       piece = nullptr;

       return;
    }
    else if (this->play->selectOrMove == MOVE && !this->play->checkValidDest(this->board, piece, wxPoint(x, y)))
    {
        drawText(wxPoint(500, 55), std::string("You already have a piece at the desired position\n"));
        piece = nullptr;
        return;
    }
   
    if (this->play->selectOrMove == SELECT)
    {
        this->play->selectOrMove = MOVE;
        return;
    }
    
    // For the MOVE part

    prevPiece = this->board->getPiece(y, x);

    if (this->play->makeMove(this->board, piece, wxPoint(x, y)))
    {
        drawText(wxPoint(0, 30), std::string("Invalid move, try again\n"));
        piece = nullptr;
        this->play->selectOrMove = SELECT;
        return;
    }

 
    moveX = piece->column * 75 + 170;
    moveY = piece->line * 75 + 55;

    //drawText(wxPoint(pt.x, pt.y), std::string(std::to_string(piece->column) + ", " + std::to_string(piece->line)));
    if (this->searchImage(piece->image) > -1)
    {
                
        if (prevPiece)
        {
            prevIndexIt = this->coords.begin();
            prevBitmapIt = this->images.begin();

            prevIndex = this->searchImage(prevPiece->image);

            for (i = 0; i < prevIndex; i++)
            {
                prevIndexIt++;
                prevBitmapIt++;
            }

            this->coords.erase(prevIndexIt);
            this->images.erase(prevBitmapIt);
        }

        this->coords[this->searchImage(piece->image)] = wxPoint(moveX, moveY);

    }
            
    this->window->Refresh();
    
    
}

