#include <stdio.h>
#include <unistd.h>

#define fork_num 10

int chapter=0;
void HanoiTower(char from, char to, char temp, int childldx, int n)
{
    if(n==1){
        printf("\n %d step %d : move from %c to %c", childldx, ++chapter, trom, to);
    } 
    else{
        HanoiTower(from, temp, to, childldx, n-1);
        HanoiTower(from, temp, to, childldx, 1);
        HanoiTower(temp, to, from, childldx, n-1);
    }
}

int main()
{
    int i;
    pid_t childs[fork_num];
    
    for(i=0; i<fork_num; ++i)
    {
        pid_t pid;
        pid = fork();
        
        if(pid<0){
            printf("\nfork error!");
        }
        else if(pid==0){
            char from='A', to='B', temp='C';
            HanoiTower('A', 'C', 'B', i+1, 100);
            printf("\n total numbers for moving all discs are %d\n", chapter);
            return 0;
        }
        else{
            printf("\n This is parent");
        }
    return 0;
    }
}
