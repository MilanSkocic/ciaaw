.PHONY: html latexpdf ford clean upload logo doxygen

all: logo doxygen latexpdf html

logo: 
	cp ../media/logo-ciaaw.png ./sphinx/source/media

html: 
	$(MAKE) -C ./sphinx html

latexpdf:
	$(MAKE) -C ./sphinx latexpdf

ford:
	$(MAKE) -C ./ford

doxygen:
	mkdir -p ./sphinx/build/html
	$(MAKE) -C ./doxygen
	$(MAKE) -C ./sphinx/build/html/doxygen/latex

clean:
	$(MAKE) -C ./sphinx clean

upload:
	rm -rf ../docs/*
	cp -r ./sphinx/build/html/* ../docs
