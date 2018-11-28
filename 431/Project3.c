#include <stdio.h>
#include <stdbool.h>
#define MAX_USED 999
#define MAX_FRAMES 3

int stack[3] = {-1, -1, -1};
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
bool stk_full();
int addused(int val);
int checkused(int val);
bool have_seen(int val);
void reset_values();

int main(void)
{
    int n = 3;
    int my_ref_str[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

    size_t sz = (sizeof(my_ref_str) / sizeof(my_ref_str[0]));
    int ref_str[sz + 1];

    for (int i = 0; i < sz; i++) {
        ref_str[i] = my_ref_str[i];
    }
    ref_str[sz] = -1;

    printf("FIFO: %d\n", FIFO(ref_str, n));
    reset_values();
    printf("LRU: %d\n", LRU(ref_str, n));
    
    /*
     * I was not able to implement the optimal page replacement
     * algorithm because I found difficulty in eliminating two
     * reference elements and keeping the "winner." Not to mention
     * solving tie-breaking scenarios, such as when two stack 
     * elements do not appear in the remainder of the reference string.
     */
    OPT(ref_str, n);
}

int FIFO(int ref_str[], int n)
{
    for(int i = 0; ref_str[i] != -1; i++) {
        for(int j = 0; j < n; j++) {
            if (ref_str[i] == stack[j]) {
                break;
            }
            if (ref_str[i] != stack[j] && j == n-1) {
                push(ref_str[i]);
                faults++;
            }
        }
    }
    return faults;
}

int LRU(int ref_str[], int n) 
{
    for (int i = 0; ref_str[i] != -1; i++) {
        for(int j = 0; j < n; j++) {
            if (ref_str[i] == stack[j]) {
                addused(ref_str[i]);
                break;
            } 
            if (ref_str[i] != stack[j] && j == n-1) {
                if (!stk_full()){
                    push(ref_str[i]);
                }
                else if (stk_full()) {
                    int my_lru = checkused(ref_str[i]);
                    if (my_lru >= 0)
                        push_lru(my_lru, ref_str[i]);
                    else {
                        push_lru(0, ref_str[i]);
                    }
                }    
                addused(ref_str[i]);
                faults++;
            }
        }
    }
    return faults;
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

bool stk_full()
{
    if (stk_idx == MAX_FRAMES - 1)
        return true;
    else
        return false;
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
    for (i = seen_idx; i >= 0; i--) {
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
    for(i = used_idx; i >= 0; --i) {
        for (j = stk_idx; j >= 0; --j) {
            if (stack[j] == used[i]) {
                if (!have_seen(used[i])) {
                    return_lru = j;
                    seen_idx++;
                    seen[seen_idx] = used[i];
                }
            }
        }
    }
    return return_lru;
}

void reset_values()
{
    stk_idx = -1;
    used[MAX_USED], used_idx = -1;
    seen[MAX_USED], seen_idx = -1;
    faults = 0;
    for (int i=0; i < MAX_FRAMES; i++) {
        stack[i] = -1;
    }
}
