//Finding the path containing all the nodes having visas
#include <stdio.h>
int paths=0;

//defining a structure to represent nodes
struct Node
{
    int nodeid;
    int adjcount;
    int adjs[20];// One node can have upto 20 adjacent nodes
    int costs[10];
};

int addNode (struct Node * p, int nid, int count) //This function adds node to the graph
{
    int i =0, ncount = count;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid) { break; }
    }
    if (i == count)
    {
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

void addAdjacent (struct Node *p, int nid1, int nid2, int cost, int count)
{
    int i =0, index;
    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == nid1)
        {
            int c = p[i].adjcount;
            p[i].adjs[c] = nid2;
            p[i].costs[c] = cost;
            p[i].adjcount = c+1;

            break;
        }
    }
}

int added (int * list, int lcount, int nid)
{
    int i =0;
    for (i=0;i<lcount;i++)
    {
        if (list[i] == nid) { return 1; }
    }
    return 0;
}


void findpath (struct Node * p, int count, int start, int end, int * list, int *clist, int lcount,int visa[100]) //this function finds paths between the start and end node
{
    int index = 0, i=0,mark=0;

    //check if list contains the end node. If it is true we have found a path
    if (list[lcount-1] == end)
    {

        for (i=1;i<lcount;i++)
        {
            if(visa[list[i]]!=1){
                mark=1;
            }
        }
        //paths++;
        if(mark==0){
            paths++;
            int tcost = 0;
        printf ("\n");
        for (i=0;i<lcount;i++)
        {
            printf (" %d ", list[i]);
            tcost += clist[i];
        }
        printf (" cost = %d", tcost);
        return;
        }
        
    }

    for (i=0;i<count;i++)
    {
        if (p[i].nodeid == start) { index = i; break; }
    }

    for (i=0;i<p[index].adjcount;i++)
    {
        int a = added (list, lcount, p[index].adjs[i]);
        if (a == 0)
        {
            list[lcount] = p[index].adjs[i];
            clist[lcount] = p[index].costs[i];
            lcount++;
            
            findpath (p, count, p[index].adjs[i], end, list, clist, lcount,visa);
            lcount--;
        }
    }
}


int main() {

    struct Node nodes[50];
    int nodecount = 0;
    int n1=0, n2=0, c = 0,visa[100];
   
    while (1)
    {
        printf ("n1, n2, cost ? ");
        scanf("%d %d %d", &n1, &n2, &c);
        if (n1 == -9 || n2 == -9 || c== -9) {break;}
        nodecount = addNode (&nodes[0], n1, nodecount);
        nodecount = addNode (&nodes[0], n2, nodecount);
       
        addAdjacent (&nodes[0], n1, n2, c, nodecount);
        addAdjacent (&nodes[0], n2, n1, c, nodecount);
    }
   
    int start, end;
    printf ("start, end ? ");
    scanf ("%d %d", &start, &end); //Inputing the start and End node
    visa[start]=1;
    int visas;
    printf("enter the countries with visa=");
    while(1)
    {
        scanf("%d",&visas);
        if(visas==-1)
        {
            break;
        }
        visa[visas]=1;

    }
    
    int list[50], clist[50], lcount = 0;
    list[0] = start; clist[0] = 0; lcount = 1;

    findpath (nodes, nodecount, start, end, list, clist, lcount,visa);
    printf ("\n paths = %d", paths);

    return 0;
}
