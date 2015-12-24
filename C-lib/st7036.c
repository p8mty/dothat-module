/* C version of dothat-module sysfs functions

sn3218 interface

 (c) P Biggs 2015

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

const char *f_clear=   "/sys/class/dothat/st7036/clear";
const char *f_contrast=      "/sys/class/dothat/st7036/contrast";
const char *f_cursor_on="/sys/class/dothat/st7036/cursor_on";
const char *f_cursor_blink="/sys/class/dothat/st7036/cursor_blink";
const char *f_cursor_position="/sys/class/dothat/st7036/cursor_position";
const char *f_lcd_buffer=  "/sys/class/dothat/st7036/lcd_buffer";
const char *f_shift_display=  "/sys/class/dothat/st7036/shift_display";

void st7036_clear(void)
{
int fd;

fd=open(f_clear, O_WRONLY | O_APPEND); 

if (fd>0) {
		dprintf(fd,"1");
	close(fd);
	};
}

void st7036_cursor_on(int enable)
{
int fd;

fd=open(f_cursor_on, O_WRONLY | O_APPEND); 

if (fd>0) {
	if (enable==0)
		dprintf(fd,"0") ;
	else
		dprintf(fd,"1");
	close(fd);
	};
}

void st7036_cursor_blink(int enable)
{
int fd;

fd=open(f_cursor_blink, O_WRONLY | O_APPEND); 

if (fd>0) {
	if (enable==0)
		dprintf(fd,"0") ;
	else
		dprintf(fd,"1");
	close(fd);
	};
}

void st7036_contrast(int contrast)
{
int fd;

fd=open(f_contrast, O_WRONLY | O_APPEND); 

if (fd>0) {
	dprintf(fd,"%i",contrast);
	close(fd);
	};
}

void st7036_cursor_position(int col, int row)
{
int fd;

fd=open(f_cursor_position, O_WRONLY | O_APPEND);

if (fd>0) {
	dprintf(fd,"%i %i",col, row);

	close(fd);
	};
}

void st7036_lcd_buffer(char *string)
{
int fd;

fd=open(f_lcd_buffer, O_WRONLY | O_APPEND);

if (fd>0) {
	dprintf(fd,"%s",string);
	close(fd);
	};
}

void st7036_shift_display(char shft)
{
int fd;

fd=open(f_shift_display, O_WRONLY | O_APPEND);

if (fd>0) {
        dprintf(fd,"%c",shft);
        close(fd);
        };
}
