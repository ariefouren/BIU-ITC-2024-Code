#include <iostream>
#include <iomanip>      // std::setw()

#define MAX_N 50
#define WIDTH 4
using namespace std; 

void calculateModRelation(bool relation[MAX_N][MAX_N], int n, int  mod);
void printRelation(bool relation[MAX_N][MAX_N], int n);

bool isReflexive(bool relation[MAX_N][MAX_N], int n);
bool isSymmetric(bool relation[MAX_N][MAX_N], int n);
bool isTransitive(bool relation[MAX_N][MAX_N], int n);

int main()
{
    
    bool modRel[MAX_N][MAX_N];
    int n;
    int mod;
    cout << "Enter the number of elements (n): ";
    cin >> n;
    cout << "Enter mod (m) :";
    cin >> mod;

    calculateModRelation(modRel, n, mod);
    printRelation(modRel, n);

    cout << "The relation is reflexive : " << isReflexive(modRel, n) <<endl;
    cout << "The relation is symmetric : " << isSymmetric(modRel, n) <<endl;
    cout << "The relation is transitive : " << isTransitive(modRel, n) <<endl;

    cout << endl;
     
    system("pause");
    return 0;
}

void calculateModRelation(bool relation[MAX_N][MAX_N], int n, int mod)
{
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                relation[i][j] = ((i - j) % mod == 0);
            }
        }
}

void printRelation(bool relation[MAX_N][MAX_N], int n)
{
    // print header
    cout << setw(WIDTH) << "";
    for(int j = 0; j < n; j++)
    {
        cout << setw(WIDTH) << j;
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << setw(WIDTH) << i;
        for(int j = 0; j < n; j++)
        {   // note the use of the conditional operator ? :
            // to print 1 if relation[i][j] is true, and a space otherwise
            // the format of the conditional operator: 
            // condition ? expression_if_true : expression_if_false;
            cout << setw(WIDTH) << ( relation[i][j] ? "1" : " ");
        }
        cout << endl;
    }
}

bool isReflexive(bool relation[MAX_N][MAX_N], int n)
{
    for(int i = 0; i < n; i++)
    {
        if( !relation[i][i] )
        {
            return false;
        } 
    }
    return true;
}

bool isSymmetric(bool relation[MAX_N][MAX_N], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(relation[i][j] && !relation[j][i]) return false; 
        }
            
    }
    return true;
}

bool isTransitive(bool relation[MAX_N][MAX_N], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(relation[i][j] && relation[j][k] && !relation[i][k]) 
                {
                    return false; 
                }
            }
        }     
    }
    return true;
}


