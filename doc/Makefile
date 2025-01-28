.PHONY: ford html clean copy

all: ford html copy

html:
	make -C sphinx html

ford: 
	make -C ford

copy: 
	mkdir -p sphinx/build/html/ford/
	cp -rf ford/build/* sphinx/build/html/ford/

clean:
	make -C ford clean
	make -C sphinx clean
