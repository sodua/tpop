import copy

class Process:

    def __init__(self,pid,bt,at=0,pr=0):
        self.pid = pid
        self.burst_time = bt
        self.arrival_clock_time = at
        self.priority = pr
        self.remaining_burst_time = bt

    def __str__(self):
        return "Process (PID="+str(self.pid)+")"

    def sim_run(self):
        self.remaining_burst_time -= 1

    def is_done(self):
        return self.remaining_burst_time == 0

def getPriority(process):
    return process.priority

def getBurstTime(process):
    return process.burst_time

def getRemainingBurstTime(process):
    return process.remaining_burst_time

def NP_PRIORITY(ready_queue):
    rq_copy = ready_queue.copy()
    sorted_rq = sorted(rq_copy, key=lambda x: x.priority)
    rq_copy = FCFS(sorted_rq)
    return rq_copy

def SJF(ready_queue):
    rq_copy = ready_queue.copy()
    sorted_rq = sorted(rq_copy, key=lambda x: x.burst_time)
    rq_copy = FCFS(sorted_rq)
    return rq_copy

def RR(ready_queue, quantum):
    rq_copy = ready_queue.copy()
    USER_MODE, KERNEL_MODE = 0,1
    mode = KERNEL_MODE
    running_process = None
    clock_time = 0
    my_quantum = quantum
    process_count = len(rq_copy)
    i = 0

    while ready_queue:
        if mode == USER_MODE and process_count > 0:
            my_quantum -= 1
            clock_time += 1
            running_process.sim_run()
            print(running_process, "q:", my_quantum, "c:", clock_time)
            if running_process.is_done():
                print(running_process, "is done")
                process_count -= 1
                mode = KERNEL_MODE
            if my_quantum == 0:
                print(i)
                print("process_count", process_count)
                if i < process_count - 1:
                    i += 1
                    running_process = ready_queue[i]
                    my_quantum = quantum
                elif i >= process_count - 1:
                    i = 0
                    running_process = ready_queue[0]
                    my_quantum = quantum
        if process_count == 0:
            mode = KERNEL_MODE

        if mode == KERNEL_MODE:
            if running_process == None:
                running_process = ready_queue[0]
            if running_process.is_done():
                running_process.finish_clock_time = clock_time
                del ready_queue[0]
                if ready_queue:
                    running_process = ready_queue[0]
            mode = USER_MODE
    return rq_copy


def FCFS(ready_queue):
    rq_copy = ready_queue.copy()
    USER_MODE, KERNEL_MODE = 0,1
    mode = KERNEL_MODE
    running_process = None
    clock_time = 0

    while ready_queue:
        print("top of while loop")
        if mode == USER_MODE:
            print("user mode")
            clock_time += 1
            print("clock_time: ", clock_time)
            print("burst time was: ", getBurstTime(running_process))
            running_process.sim_run()
            print("burst time now: ", getBurstTime(running_process))
            if running_process.is_done():
                print("running_process is done from user mode")
                mode = KERNEL_MODE
                print("mode set to kernel mode")
        elif mode == KERNEL_MODE:
            print("kernel mode")
            if running_process == None:
                running_process = ready_queue[0]
                print("no running process, so set to ready_queue[0]")
            if running_process.is_done():
                print("running process is done from kernel mode")
                running_process.finish_clock_time = clock_time
                print("process finished with clock_time ", clock_time)
                print("deleting ", ready_queue[0])
                del ready_queue[0]
                if ready_queue:
                    print("ready_queue not empty")
                    running_process = ready_queue[0]
                    print("running process set to ", running_process)
            mode = USER_MODE
            print("user mode entered from kernel mode")
    return rq_copy

def printStats(process_list):
    total_turnaround_t, total_wait_t = 0, 0
    for p in process_list:
        print(p,end=': ')
        turnaround_t = p.finish_clock_time - p.arrival_clock_time
        total_turnaround_t += turnaround_t
        wait_t = turnaround_t - p.burst_time
        total_wait_t += wait_t
        print("turnaround time = "+str(turnaround_t)+", wait time = "+str(wait_t))
    n = len(process_list)
    avg_turnaround_t = round( total_turnaround_t / n, 2)
    avg_wait_t = round( total_wait_t / n, 2)
    print("\naverage turnaround time = "+str(avg_turnaround_t) +", average wait time = "+str(avg_wait_t))

READY_QUEUE = [ Process(1,10,pr=3), Process(2,8,pr=1), Process(3,4,pr=2) ]

#print("\n\nFCFS SCHEDULING")
#printStats( FCFS(copy.deepcopy(READY_QUEUE)) )
#print("\n\nNP_PRIORITY SCHEDULING")
#printStats( NP_PRIORITY(copy.deepcopy(READY_QUEUE)) )
#print("\n\nSJF SCHEDULING")
#printStats( SJF(copy.deepcopy(READY_QUEUE)) )
print("\n\nRR SCHEDULING")
printStats( RR(copy.deepcopy(READY_QUEUE), 4) )


