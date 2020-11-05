/**

The MIT License (MIT)

Copyright (c) 2016 Zack Bartel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>



#define BUF 32
#define STEPS 10

#define MAX_PATH "/sys/class/backlight/gmux_backlight/max_brightness"
#define CUR_PATH "/sys/class/backlight/gmux_backlight/brightness"

int delta = 1, step = 0, change = 0;

int read_int(int fd) {
    char buf[BUF];
    int r = read(fd, buf, BUF);
    return atoi(buf);
}

int get_max() {
    int fd = open(MAX_PATH, O_RDONLY);
    int max = read_int(fd);
    close(fd);
    return max;
}

int write_int(int fd, int val) {
    char buf[BUF];
    sprintf(buf, "%d", val);
    return write(fd, buf, strlen(buf));
}

int opts(int argc, char** argv) {
    int i;
    for (i = 0; i < argc; i++) {
        char opt = argv[i][0];
        switch (opt) {
            case 'u':
                delta = 1;
                break;
            case 'd':
                delta = -1;
                break;
            case 's':
                delta = 1;
                change = atoi(argv[++i]);
                break;
        }
    }
    return 0;
}

int main(int argc, char** argv) {

    int ret = opts(argc, argv);

    if (ret  > 0) {
        printf("Invalid\n");
        return ret;
    }

    int max = get_max();
    step = max / STEPS;

    int fd = open(CUR_PATH, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 2;
    }

    int current = read_int(fd);

    printf("delta = %d, step = %d change = %d\n", delta, step, change);

    int final = change > 0 ? change : current + delta * step;

    if (final < 0) final = 0;
    if (final > max) final = max;

    write_int(fd, final);

    close(fd);

    return 0;
}
