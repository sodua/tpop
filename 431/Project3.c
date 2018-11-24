#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_USED 999

int stack[MAX_FRAMES] = {-1, -1, -1};
int stk_idx = -1;
int used[MAX_USED], used_idx = -1;

int faults = 0;

int FIFO(int ref_str[], int n);
int LRU(int ref_str[], int n);
int OPT(int ref_str[], int n);

void pop();
void push(int val);
void push_lru(int val);
int addused(int val);
int checkused(int val);

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

int LRU(int ref_str[], int n)
{
    // compare ref with all items in stack, if not found faults++
    // else i++
    // add each ref_str[i] to another stack
    // check used[] for match with lowest j
    // if stack is empty or less than MAX-1, add to stack
    // if stack is full, pop then add to stack
    for (int i = 0; ref_str[i] != -1; i++) {
        printf("\nSTACK: [");
        for (int s = 0; s <= stk_idx; s++) {
            printf("%d", stack[s]);
        }
        printf("]\n");
        for(int j = 0; j < MAX_FRAMES; j++) {
            if (ref_str[i] == stack[j]) {
                printf("MATCH FOUND: j = %d. ref: %d == ", stack[j], ref_str[i]);
                addused(ref_str[i]);
                break;
            } 
            if (ref_str[i] != stack[j] && j == MAX_FRAMES - 1) {
                push(ref_str[i]);
                int my_lru = checkused(ref_str[i]);
                if (my_lru >= 0)
                    printf("LRU VALUE: %d\n", used[my_lru]);
                printf("NO MATCH: pushed %d onto stack\n", ref_str[i]);
                addused(ref_str[i]);
                faults++;
            }
            
        }
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
        printf("Deleting %d\n", stack[0]);
        for(int i = 0; i < MAX_FRAMES - 1; i++) {
            stack[i] = stack[i + 1];
        }
        stk_idx--;
    }
}

void push(int val)
{
    if (stk_idx == MAX_FRAMES - 1) {
        pop(); 
    }
    stk_idx++;
    stack[stk_idx] = val;
}

void push_lru(int val)
{
    if (stk_idx == MAX_FRAMES - 1) {
        pop(); 
    }
    stk_idx++;
    stack[stk_idx] = val;
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

int checkused(int val) {
    int lru_val = -1;
    for(int i = used_idx; i > 0; i--) {
        if (used[i] == val) {
            lru_val = i;
        }
    }
    printf("lru_val to be returned: %d\n", lru_val);
    return lru_val;
}

