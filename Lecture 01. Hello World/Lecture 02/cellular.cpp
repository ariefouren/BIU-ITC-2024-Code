#include <iostream>

using namespace std;

int main()
{
    double xp, yp, x1, y1, x2, y2;
    double xMin, xMax, yMin, yMax;

    cout << "Enter x y of the phone : ";
    cin >> xp >> yp;

    cout << "Enter x1 y1 x2 y2 of the building : ";
    cin >> x1 >> y1 >> x2 >> y2;
  
    // find minX, minY, ...
    if(x1 < x2) 
    {
        xMin = x1;
        xMax = x2;
    }
    else
    {
        xMin = x2;
        xMax = x1;
    }

    if(y1 < y2) 
    {
        yMin = y1;
        yMax = y2;
    }
    else
    {
        yMin = y2;
        yMax = y1;
    }

    if((xMin <= xp) && (xp <= xMax ) && 
        (yMin <= yp) && (yp <= yMax ))
    {
        cout << "The phone is INSIDE the building" << endl;
    }
    else 
    {
        cout << "The phone is OUTSIDE the building" << endl;
    }

// De-Morgan :)
    if( !(xp < xMin || xMax < xp || yp < yMin || yMax < yp) )
    {
        cout << "The phone is INSIDE the building" << endl;
    }
    else 
    {
        cout << "The phone is OUTSIDE the building" << endl;
    }

    system("pause");
    return 0;
}
