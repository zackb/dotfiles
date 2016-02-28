#include <stdio.h>
#include <string.h>
#include <fcntl.h>


#define BUF 32

#define MAX_PATH "/sys/class/backlight/gmux_backlight/max_brightness"
#define CUR_PATH "/sys/class/backlight/gmux_backlight/brightness"

int get_max() {
    int fd = open(MAX_PATH, O_RDONLY);
    int max = read_int(fd);
    close(fd);
    return max;
}

int read_int(int fd) {
    char buf[BUF];
    int r = read(fd, buf, BUF);
    return atoi(buf);
}

int write_int(int fd, int val) {
    char buf[BUF];
    sprintf(buf, "%d", val);
    return write(fd, buf, strlen(buf));
}

int main(int argc, char** argv) {
    int max = get_max();
    int fd = open(CUR_PATH, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 2;
    }

    int current = read_int(fd);

    printf("%d %d\n", current, max);

    write_int(fd, current / 2);

    close(fd);

    return 0;
}

