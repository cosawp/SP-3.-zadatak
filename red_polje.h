#define max 1000
using namespace std;

struct tdata
{
    char Ime[20], Prezime[20], spol;
    tm DatumR;
    int ai, bi, ci, di;
    };
     
struct tlist
{
    tdata data[max];
    int front, rear;
    };
     
int AddOne(int n)
{
    return (( n + 1 ) % max);
    }
     
bool IsEmptyQ (tlist *Q)
{
    if (AddOne (Q -> rear) == Q -> front)
       return true;
    return false;
    }
     
tdata FrontQ (tlist *Q)
{
    if (IsEmptyQ (Q))
                 cout << "Red je prazan." << endl;
    else
        return Q -> data[Q -> front];
    }
     
void EnQueueQ(tdata x, tlist *Q)
{
    if (AddOne (AddOne (Q -> rear)) == Q -> front)
    {
               cout << "Red je pun!";
               return;
               }
    Q -> rear = AddOne (Q -> rear);
    Q -> data[Q -> rear] = x;
    }
     
bool DeQueueQ (tlist *Q)
{
    if (IsEmptyQ (Q))
       return false;
    Q -> front = AddOne (Q -> front);
    return true;
    }
     
tlist* InitQ (tlist *Q)
{
    Q = new tlist;
    Q -> rear = max - 1;
    Q -> front = 0;
    return Q;
    }
