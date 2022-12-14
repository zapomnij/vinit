/*
MIT License

Copyright (c) 2022 Zapomnij

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

#include <stddef.h>
enum scripttype {
	respawn,
	oneshot,
	wait,
};

struct script {
	char *cmd;
	enum scripttype type;
};

struct inittab {
	char *sysinit, *shutdown, *reboot, *halt;

	size_t postn;
	struct script *post;
};

struct inittab *parseInittab(const char *inittab);

char **splitString(char *buf, const char *splitter);
char *readFile(const char *path);

#include <unistd.h>
int runShellCmd(char *const cmd);
pid_t runAndFork(char *const cmd);
pid_t respawnCmd(char *const cmd);

void handle_sigchld();

#define VERSION "0.1.0"