.PHONY: ford html

all: ford html copy

html:
	make -C sphinx html

ford: 
	make -C ford

copy: 
	mkdir -p sphinx/build/html/ford/
	cp -rf ford/build/* sphinx/build/html/ford/
