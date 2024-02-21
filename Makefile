
all:
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C console


rm: 
	$(MAKE) rm -C mySimpleComputer
	$(MAKE) rm -C console