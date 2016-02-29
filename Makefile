default: dback
dback:
	gcc bin/dback.c -o dback
	sudo chown root:root bin/dback
	sudo chmod u+s bin/dback
.PHONY: dback
