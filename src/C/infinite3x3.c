#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct pos {
    int x1,y1,x2,y2;
};

void initialize_positions(struct pos* p)
{
    p[0].x1=0;
    p[0].y1=0;
    p[0].x2=0;
    p[0].y2=1;
    
    p[1].x1=1;
    p[1].y1=1;
    p[1].x2=0;
    p[1].y2=1;
    
    p[2].x1=1;
    p[2].y1=1;
    p[2].x2=2;
    p[2].y2=1;
    
    p[3].x1=2;
    p[3].y1=2;
    p[3].x2=2;
    p[3].y2=1;
    
    p[4].x1=2;
    p[4].y1=2;
    p[4].x2=1;
    p[4].y2=2;
    
    p[5].x1=0;
    p[5].y1=2;
    p[5].x2=1;
    p[5].y2=2;
    
    p[6].x1=0;
    p[6].y1=2;
    p[6].x2=0;
    p[6].y2=1;
    
    p[7].x1=1;
    p[7].y1=1;
    p[7].x2=0;
    p[7].y2=1;
    
    p[8].x1=2;
    p[8].y1=1;
    p[8].x2=1;
    p[8].y2=1;
    
    p[9].x1=2;
    p[9].y1=0;
    p[9].x2=2;
    p[9].y2=1;
    
    p[10].x1=2;
    p[10].y1=0;
    p[10].x2=1;
    p[10].y2=0;
    
    p[11].x1=0;
    p[11].y1=0;
    p[11].x2=1;
    p[11].y2=0;
}

int main()
{

    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 100 * 1000 * 1000; // 10 milliseconds in nanoseconds (10,000,000 ns)

    char **a = (char**)calloc(3,sizeof(char*));
    struct pos* p = (struct pos*)calloc(12,sizeof(struct pos));
    initialize_positions(p);

    for(int x=0;x<3;x++)a[x] = (char*)calloc(3,sizeof(char));
    for(int x=0;x<3;x++)for(int y=0;y<3;y++) {
        a[x][y]='_';
        
    }
    
    while(1){
        int j=0;
        while(j<12) {
        printf("\033[1;1H");
        for(int x=0;x<3;x++)for(int y=0;y<3;y++) {
            a[x][y]='_';
        }
            for(int x=0;x<3;x++)for(int y=0;y<3;y++) {if(p[j].x1==x&&p[j].y1==y||p[j].x2==x&&p[j].y2==y)a[x][y]='*'; else a[x][y]='_';}    
            for(int x=0;x<3;x++){for(int y=0;y<3;y++) {printf("%c",a[x][y]);}printf("\n");}
            printf("\n");
            j++;
            nanosleep(&ts, NULL);
        }
        
    }
    
    // I know these are useless but I will fix this in next commit
    for(int x=0;x<3;x++)free(a[x]);
    free(a);
    free(p);
            

    return 0;
}