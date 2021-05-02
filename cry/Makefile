.PHONY: compress clean

CHALLENGES := $(filter-out Makefile, $(wildcard *))

compress:
	$(foreach challenge, $(CHALLENGES), $(shell \
		mkdir -p __tmp/$(challenge); \
		cp $(challenge)/file/* __tmp/$(challenge); \
		tar czf $(challenge).tar.gz -C __tmp $(challenge); \
		mv $(challenge).tar.gz $(challenge)/file/$(challenge).tar.gz; \
		rm -rf __tmp))

clean:
	$(foreach challenge, $(CHALLENGES), $(shell \
		rm -f $(challenge)/file/$(challenge).tar.gz))


