
all:
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) -C console


rm: 
	$(MAKE) rm -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) rm -C console