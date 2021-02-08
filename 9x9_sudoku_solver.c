#include <stdio.h>
void printfunc(int a[][10]);
int (*(checposs)(int a[][10]))[10];
void gridsolve(int a[][10],int k,int *n,int l,int m);
void fseg(int a[][10],int (*b)[10],int *i,int *j);
int checposs_beta(int a[][10]);
int comchec(int a[][10]);
void kolinfunc(int a[][10],int* b,int* c);
void kolinfunc(int a[][10],int* b,int* c)
{
    if(checposs_beta(a)==0)
    {
        //printf("#1b=0\n");
        *b=0;
        return;
    }
    if(comchec(a)==1)
    {  
        //printf("#1c=1\n");
        *c=1;
        return;
    }
    int (*d)[10];
    d=checposs(a);
    //printf("\n-------\n");
    //printfunc(d);
    //printf("-------\n");
    int l,m;
    fseg(a,d,&l,&m);
    //printf("%d %d",l,m);
    int k=1;
    int n=1;
    while(k<10)
    {
        int x=1;
        n=1;
        while(x<10)
        {
            if(a[l][x]==k)
            {
                x=0;
                break;
            }
            x=x+1;
        }
        int y=1;
        while(y<10)
        {
            if(a[y][m]==k)
            {
                y=0;
                break;
            }
            y=y+1;
        }
        gridsolve(a,k,&n,l,m);
        /*if (a[l-1+2*(l%2)][m]==k)
		{
		  n=0;
		}
	      if(a[l][m-1+2*(m%2)]==k)
		{
		  n = 0;
		}
	      if (a[l-1+2*(l%2)][m-1+2*(m%2)]==k)
		{
		  n = 0;
		}*/
		if((n!=0)&&(x!=0)&&(y!=0))
        {
            a[l][m]=k;
            /*printf("\n");
            printfunc(a);
            printf("\n");*/
            if(checposs_beta(a)==0)
            {
                k=k+1;
                a[l][m]=0;
                continue;
            }
            //printf("\n0\n");
            //printfunc(a);
            kolinfunc(a,b,c);
            //printf("\n1\n");
            //printfunc(a);
            if(*b==0)
            {  
                //printf("#2 b=1\n");
                *b=1;
                k=k+1;
                a[l][m]=0;
                //printf("2\n");
                //printfunc(a);
                continue;
            }
            if(comchec(a)==1)
            {  
                //printf("#2 c=1\n");
                *c=1;
                return;
            }
        }        
        k=k+1;
    }
    //printf("#3 b=0\n");
    *b=0;
}

int main()
{
    int i,j,a[10][10];
    i=1;
    j=1;
    while(i<10)
    {
        j=1;
        while(j<10)
        {
            scanf("%d   ",&a[i][j]);
            j=j+1;
        }
        printf("\n");
        i=i+1;
    }
    int b,c;
    b=1;
    c=0;
   kolinfunc(a,&b,&c);
   i=1;
   j=1;
   while(i<10)
   {
       j=1;
       while(j<10)
       {
           printf("%d  ",a[i][j]);
           j=j+1;
       }
       printf("\n");
       i=i+1;
   }
    return 0;
}
int (*(checposs)(int a[][10]))[10]
{
  int i = 1;
  static int b[10][10];
  while (i < 10)
    {
      int j = 1;
      while (j < 10)
	{
	  b[i][j] = 9;
	  if (a[i][j] !=0)
	    {
	      b[i][j] = 1;
	      j = j + 1;
	      continue;
	    } 
	  int k = 1;
	  while (k < 10)
	    {
	      int l = 1;
	      int m = 1;
	      int n = 1;
	      while (l < 10)
		{
		  if (a[i][l] == k)
		    {
		      l = 0;
		      break;
		    }
		  l = l + 1;
		}
	      while (m < 10)
		{
		  if (a[m][j] == k)
		    {
		      m = 0;
		      break;
		    }
		  m = m + 1;
		}
		gridsolve(a,k,&n,i,j);
	     /* if (a[i - 1 + 2 * (i % 2)][j] == k)
		{
		  n = 0;
		}
	      if (a[i][j - 1 + 2 * (j % 2)] == k)
		{
		  n = 0;
		}
	      if (a[i - 1 + 2 * (i % 2)][j - 1 + 2 * (j % 2)] == k)
		{
		  n = 0;
		} */
	      if (n == 0 || l == 0 || m == 0)
		{
		  b[i][j] = b[i][j] - 1;
		}
	      k = k + 1;
	    }

	  j = j + 1;
	}
      printf ("\n");
      i = i + 1;
    }
  return b;
}
int checposs_beta(int a[][10])
{
    int (*b)[10],i,j;
    b=checposs(a);
    i=1;
    j=1;
    while(i<10)
    {
        j=1;
        while(j<10)
        {
            if(b[i][j]==0)
            {
                return 0;
            }
            j=j+1;
        }
        i=i+1;
    }
    return 1;
}
void fseg(int a[][10],int (*b)[10],int *i,int *j)
{
  int l,m;
  l=1;
  m=1;
  int k=9;
  while(l<10)
  {
      m=1;
      while(m<10)
      {
          if(a[l][m]!=0)
          {
              m=m+1;
              continue;
          }
          if(b[l][m]<k)
          {
              k=b[l][m];
              *i=l;
              *j=m;
          }
          m=m+1;
      }
      l=l+1;
  }
}

int comchec(int a[][10])
{
    int i,j;
    i=1;
    j=1;
    while(i<10)
    {
        j=1;
        while(j<10)
        {
            if(a[i][j]==0)
            {
                return 0;
            }
            j=j+1;
        }
        i=i+1;
    }
    return 1;
}
void printfunc(int a[][10])
{
  int i,j;
  i=1;
  while(i<10)
  {
      j=1;
      while(j<10)
      {
        printf("%d ",a[i][j]);
        j=j+1;
      }
      i=i+1;
      printf("\n");
  }
}
void gridsolve(int a[][10],int k,int*n,int l,int m)
{
  int i,j;
  i=1;
  j=1;
  *n=1;
  while(i<4)
  {
      j=1;
      while(j<4)
      {
          if(j==(m%3)&&i==(l%3))
          {
              j=j+1;
              continue;
          }
          if(a[i+l-1-((l-1)%3)][j+m-1-((m-1)%3)]==k)
          {
              *n=0;
              return;
          }
          j=j+1;
      }
      i=i+1;
  }
    
}

