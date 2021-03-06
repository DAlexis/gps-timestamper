#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include <sys/time.h>
#include <usbd_cdc_if.h>

#if defined STM32F1
# include <stm32f1xx_hal.h>
#elif defined STM32F2
# include <stm32f2xx_hal.h>
#elif defined STM32F4
# include <stm32f4xx_hal.h>
#endif

#include "cmsis_os.h"

#define USB_WRITE_MIN_DELAY   1

//extern uint32_t __get_MSP(void);

#ifdef USE_UART_DEBUG_OUTPUT
    extern UART_HandleTypeDef huart1;
#endif
//extern uint64_t virtualTimer;

#undef errno
extern int errno;


char *__env[1] = { 0 };
char **environ = __env;

int _write(int file, char *ptr, int len);

void _exit(int status)
{
    while (1);
}

int _close(int file)
{
    return -1;
}

int _execve(char *name, char **argv, char **env)
{
    errno = ENOMEM;
    return -1;
}

int _fork()
{
    errno = EAGAIN;
    return -1;
}

int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int _getpid()
{
    return 1;
}
/*
int _gettimeofday(struct timeval *tv, struct timezone *tz)
{
    tv->tv_sec = virtualTimer / 1000;
    tv->tv_usec = (virtualTimer % 1000) * 1000;
    return 0;
}*/

int _isatty(int file)
{
    switch (file)
    {
    case STDOUT_FILENO:
    case STDERR_FILENO:
    case STDIN_FILENO:
        return 1;
    default:
        //errno = ENOTTY;
        errno = EBADF;
        return 0;
    }
}

int _kill(int pid, int sig)
{
    errno = EINVAL;
    return (-1);
}

int _link(char *old, char *new)
{
    errno = EMLINK;
    return -1;
}

int _lseek(int file, int ptr, int dir)
{
    return 0;
}

caddr_t _sbrk(int incr)
{
	extern char __bss_end__;
	extern char _estack;
	char* heapLimit = &_estack - 0x200;

    //extern char isMemoryCorrupted;

    static char* current_heap_end;
    char* current_block_address;

    if (current_heap_end == 0)
    {
      current_heap_end = &__bss_end__;
    }

    current_block_address = current_heap_end;

    // Need to align heap to word boundary, else will get
    // hard faults on Cortex-M0. So we assume that heap starts on
    // word boundary, hence make sure we always add a multiple of
    // 4 to it.
    incr = (incr + 3) & (~3); // align value to 4
    if (current_heap_end + incr > heapLimit)
    {
      // Some of the libstdc++-v3 tests rely upon detecting
      // out of memory errors, so do not abort here.
    #if 0
      extern void abort (void);
      _write (1, "_sbrk: Heap and stack collision\n", 32);
      abort ();
    #else
      // Heap has overflowed
      //isMemoryCorrupted = 1;

      errno = ENOMEM;
      return (caddr_t) - 1;
    #endif
    }

    current_heap_end += incr;

    return (caddr_t) current_block_address;
}

int _read(int file, char *ptr, int len)
{
    switch (file)
    {
    case STDIN_FILENO:
    	//CDC_Receive_FS(ptr, len);
        //HAL_UART_Receive(&UART_Handle, (uint8_t *)ptr, 1, HAL_MAX_DELAY);
        //return 1;
    default:
        errno = EBADF;
        return -1;
    }
}

int _stat(const char *filepath, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

clock_t _times(struct tms *buf)
{
    return -1;
}

int _unlink(char *name)
{
    errno = ENOENT;
    return -1;
}

int _wait(int *status)
{
    errno = ECHILD;
    return -1;
}

int _write(int file, char *ptr, int len)
{
	static xSemaphoreHandle mutex = NULL;
	if (!mutex)
		mutex = xSemaphoreCreateMutex();
	static uint32_t lastTime = 0;
	uint32_t time = HAL_GetTick();
    switch (file)
    {
    case STDOUT_FILENO: // stdout
    case STDERR_FILENO: // stderr
    	xSemaphoreTake(mutex, portMAX_DELAY);
    	if (time - lastTime < USB_WRITE_MIN_DELAY)
    		HAL_Delay(USB_WRITE_MIN_DELAY);
    	CDC_Transmit_FS(ptr, len);
    	lastTime =  HAL_GetTick();
    	xSemaphoreGive(mutex);
        break;
    default:
        errno = EBADF;

        return -1;
    }
    return len;
}
