
all:
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) -C myBigChars
	$(MAKE) -C myReadKey
	$(MAKE) -C console


rm: 
	$(MAKE) rm -C mySimpleComputer
	$(MAKE) rm -C myTerm
	$(MAKE) rm -C myBigChars
	$(MAKE) rm -C myReadKey
	$(MAKE) rm -C console