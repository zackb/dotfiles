default: dback
dback:
	gcc dback.c -o dback
	sudo chown root:root dback
	sudo chmod u+s dback
.PHONY: dback
