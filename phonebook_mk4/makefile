include makefile.conf

$(TARGET_NAMES) : $(TARGET_OBJS)
	$(CC) $(OFLAG) $@ $^	

	
.PHONY: objOnly sourceOnly description test 
clean:
	rm -rf  $(TARGET_OBJS)  $(TARGET_NAMES)
sourceOnly:
	$(TARGET_OBJS): $(TARGET_SRCS)
		$(CC) $(CFLAG) $^
objOnly:
	$(TARGET_NAMES) : $(TARGET_OBJS)
		$(CC) $(OFLAG) $@ $^
description:
	@echo "makefile for compiling $(TARGET_NAMES) "
test:
	./phonebook_main 1 James@Borg.com
