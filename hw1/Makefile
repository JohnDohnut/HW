include Makefile.conf

$(TARGET_NAMES) : $(TARGET_OBJS)
	$(CC) $(OFLAG) $@ $^	

$(TARGET_OBJS): $(TARGET_SRCS)
	$(CC) $(CFLAG) $^	
.PHONY: objOnly binOnly description 
clean:
	rm -rf  $(TARGET_OBJS)
	rm -rf  $(TARGET_NAMES)
objOnly:
	$(TARGET_OBJS): $(TARGET_SRCS)
	$(CC) $(CFLAG) $^
binOnly:
	$(TARGET_NAMES) : $(TARGET_OBJS)
	$(CC) $(OFLAG) $@ $^
description:
	@echo "makefile for compiling $(TARGET_NAMES) "
