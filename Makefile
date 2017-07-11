top = .
src = $(top)/src

prod: 
	$(MAKE) -C $(src)

.PHONY: clean
clean:
	$(MAKE) -C $(src) clean
