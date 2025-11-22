#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    int i = 0;
    int limit = 1000; // 默认运行 1000 秒

    // 如果命令行有参数，可以指定运行多少秒
    if (argc > 1) {
        limit = atoi(argv[1]);
    }

    pid_t pid = getpid();

    while (i < limit) {
        // 打印当前进程ID和计数
        printf("(PID: %d) Counting: %d\n", pid, i);
        
        // 强制刷新缓冲区，确保在后台运行时也能立刻看到输出
        fflush(stdout); 
        
        // 睡眠 1 秒
        sleep(1);
        i++;
    }
    
    printf("(PID: %d) Finished.\n", pid);
    return 0;
}
