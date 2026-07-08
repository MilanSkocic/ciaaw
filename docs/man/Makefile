include ../../make.in

MANSRC=ciaaw.3.man ciaaw_cli.1.man ciaaw_version.3.man
MAN=$(patsubst %.man, %, $(MANSRC))
MANPDF=$(patsubst %, %.pdf, $(MAN))
MANTXT=$(patsubst %, %.txt, $(MAN))
MANGZ=$(patsubst %, %.gz, $(MAN))
MANHTML=$(patsubst %, %.html, $(MAN))

BOOKMAN=$(FPM_NAME)-bookman.pdf

all: examples $(MAN) $(BOOKMAN) $(MANGZ) $(MANPDF) $(MANTXT) $(MANHTML)

examples: 
	./concatex

$(BOOKMAN): $(MANBUILD)
	bookman -p -a "$(FPM_AUTHOR)" -t $(FPM_NAME) -v "User Commands & Libary Functions Manual" -r $(FPM_VERSION) $(MAN) > $(BOOKMAN)

ciaaw.3: ciaaw.3.man
	cat $< examples.man seealso.man > tmp
	sed -E "s/@VERSION@/$(FPM_VERSION)/g;s/@DATE@/$(shell date +'%d %B %Y')/g" tmp > $@
	rm -rfv tmp

ciaaw_version.3: ciaaw_version.3.man
	cat $< seealso.man > tmp
	sed -E "s/@VERSION@/$(FPM_VERSION)/g;s/@DATE@/$(shell date +'%d %B %Y')/g" tmp > $@
	rm -rfv tmp

ciaaw_cli.1: ciaaw_cli.1.man
	cat $< seealso.man > tmp
	sed -E "s/@VERSION@/$(FPM_VERSION)/g;s/@DATE@/$(shell date +'%d %B %Y')/g" tmp > $@
	rm -rfv tmp

%.pdf: %
	man -l -Tpdf $< > $@

%.html: %
	man -l -Thtml $< > $@

%.gz: %
	gzip -fk $^ > $@

%.txt: %
	man -l $< > $@

.PHONY: clean
clean:
	rm -fv $(MAN) $(BOOKMAN) $(MANGZ) $(MANPDF) $(MANTXT) $(MANHTML)

