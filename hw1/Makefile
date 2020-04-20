include Makefile.conf

$(TARGET_NAMES) : $(TARGET_OBJS)
	$(CC) $(OFLAG) $@ $^	

$(TARGET_OBJS): $(TARGET_SRCS)
	$(CC) $(CFLAG) $^	
.PHONY: clean description
clean:
	rm -rf  $(TARGET_OBJS)
	rm -rf  $(TARGET_NAMES)

description:
	@echo "makefile for compiling $(TARGET_NAMES) "
