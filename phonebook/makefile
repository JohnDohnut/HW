include makefile.conf

$(TARGET_NAMES) : $(TARGET_OBJS)
	$(CC) $(OFLAG) $@ $^	

	
.PHONY: objOnly sourceOnly description 
clean:
	rm -rf  $(TARGET_OBJS)
	rm -rf  $(TARGET_NAMES)
sourceOnly:
	$(TARGET_OBJS): $(TARGET_SRCS)
		$(CC) $(CFLAG) $^
objOnly:
	$(TARGET_NAMES) : $(TARGET_OBJS)
		$(CC) $(OFLAG) $@ $^
description:
	@echo "makefile for compiling $(TARGET_NAMES) "
