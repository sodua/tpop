#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 3
#define MAX_USED 999

int stack[MAX_FRAMES] = {-1, -1, -1};
int stk_idx = -1;
int used[MAX_USED], used_idx = -1;
int seen[MAX_USED], seen_idx = -1;

int faults = 0;

int FIFO(int ref_str[], int n);
int LRU(int ref_str[], int n);
int OPT(int ref_str[], int n);

void pop();
void push(int val);
void push_lru(int pos, int val);
int stk_full();
int addused(int val);
int checkused(int val);
bool have_seen(int val);

int main(void)
{
    int n = MAX_FRAMES;
    int my_ref_str[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

    size_t sz = (sizeof(my_ref_str) / sizeof(my_ref_str[0]));
    int ref_str[sz + 1];

    for (int i = 0; i < sz; i++) {
        ref_str[i] = my_ref_str[i];
    }
    
    ref_str[sz] = -1;

    FIFO(ref_str, n);
    LRU(ref_str, n);
    OPT(ref_str, n);
}

int FIFO(int ref_str[], int n)
{
}

int LRU(int ref_str[], int n) {
for (int i = 0; ref_str[i] != -1; i++) {
    printf("REF: %d\n", ref_str[i]);
    for(int j = 0; j < MAX_FRAMES; j++) {
        if (ref_str[i] == stack[j]) {
            printf("MATCH FOUND: %d == %d\n", stack[j], ref_str[i]);
            addused(ref_str[i]);
            break;
        } 
        if (ref_str[i] != stack[j] && j == MAX_FRAMES - 1) {
            if (!stk_full()){
                push(ref_str[i]);
                printf("HIT STACK NOT FULL\n");
            }
            else if (stk_full()) {
                int my_lru = checkused(ref_str[i]);
                printf("my_lru: %d\n", my_lru);
                if (my_lru >= 0)
                    push_lru(my_lru, ref_str[i]);
                else {
                    push_lru(0, ref_str[i]);
                    printf("pushing %d to 0 of stack\n", ref_str[i]);
                }
            }    
            addused(ref_str[i]);
            faults++;
        }
    }
    printf("\nSTACK: [");
    for (int s = 0; s < 3; s++) {
        printf("%d", stack[s]);
    }
    printf("]\n");
    printf("\nUSED: [");
    for (int s = 0; s < used_idx; s++) {
        printf("%d", used[s]);
    }
    printf("]\n");
}
printf("FAULTS: %d\n", faults);
}

int OPT(int ref_str[], int n)
{

}

void pop()
{
    if (stk_idx == -1) {
        //empty
    }
    else {
        for(int i = 0; i < MAX_FRAMES - 1; i++) {
            stack[i] = stack[i + 1];
        }
        stk_idx--;
    }
}

int stk_full()
{
    if (stk_idx == MAX_FRAMES - 1)
        return 1;
    else
        return 0;
}

void push(int val)
{
    if (stk_idx == MAX_FRAMES - 1) {
        pop(); 
    }
    stk_idx++;
    stack[stk_idx] = val;
}

void push_lru(int pos, int val)
{
    stack[pos] = val;
    if (stk_idx > MAX_FRAMES)
        stk_idx--;
}

int addused(int val)
{
    if (used_idx == MAX_USED - 1) {
        // full
        return -1;
    }
    else {
        used_idx++;
        used[used_idx] = val;
    }
}
bool have_seen(int val) {
    int i;
    for (i = seen_idx; i > -1; i--) {
        if (seen[i] == val)
            return true;
    }
    return false;
}

int checkused(int val) {
    int lru_val = -1;
    int return_lru = -1;
    int i, j;
    seen_idx = -1;
    for(i = used_idx; i > -1; --i) {
        for (j = stk_idx; j > -1; --j) {
            printf("CHECKING %d against %d\n", stack[j], used[i]);
            if (stack[j] == used[i]) {
                if (!have_seen(used[i])) {
                    return_lru = j;
                    seen_idx++;
                    seen[seen_idx] = used[i];
                    printf("SAVING %d to SEEN!\n", used[i]);
                }
            }
        }
    }
    return return_lru;
}
