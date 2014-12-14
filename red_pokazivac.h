using namespace std;

struct tdata
{
    char Ime[20], Prezime[20], spol;
    tm DatumR;
    int ai, bi, ci, di;
    tdata *next;
    };
     
struct tlist
{
    tdata *front;
    tdata *rear;
    };
     
bool IsEmptyQ (tlist *Q)
{
    if(Q -> front == Q -> rear)
       return true;
    return false;
    }
     
tdata FrontQ (tlist *Q)
{
    if (Q -> rear != Q -> front)
       return *(Q -> front -> next);
    else
        cout << "Red je prazan!" << endl;
    }
     
void EnQueueQ(tdata x,tlist *Q)
{
    tdata *novi = new tdata;
    memcpy(novi,&x,sizeof(tdata));
    novi->next = NULL;
    if (IsEmptyQ (Q))
    {
                    Q->front->next = novi;
                    Q->rear = novi;
    } 
    else 
    {
         Q -> rear -> next = novi;
         Q -> rear = novi;
    }
}
     
bool DeQueueQ(tlist *Q)
{
    tdata *brisi = new tdata;
    if (Q -> rear != Q -> front)
    {
          brisi = Q -> front;
          Q -> front = brisi -> next;
          delete brisi;
       }
    else
        cout << "Red je prazan!" << endl;
    }
     
tlist* InitQ(tlist *Q)
{
    Q = new tlist;
    Q -> front = new tdata;
    Q -> front -> next = NULL;
    Q -> rear = Q -> front;
    return Q;
    }
