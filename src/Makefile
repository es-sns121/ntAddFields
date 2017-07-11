top = ..

bin = $(top)/bin
exe = $(bin)/database

include $(top)/configure/config

all: database

srcs = record.cpp main.cpp
dep = record.h $(srcs)

database: record.h record.cpp main.cpp
	mkdir -p $(bin)
	g++ $(CPP_FLAGS) $(EPICS_INCLUDE) $(EPICS_LIBRARY) $(srcs) -o $(exe)

.PHONY: clean
clean:
	@printf "Removing database binary...\n"
	@mkdir -p $(bin)
	rm -rf $(exe)
