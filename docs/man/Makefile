include ../../make.in

MANSRC=ciaaw.1.man \
	   ciaaw_lib.3.man \
	   ciaaw_version.3.man \
	   ciaaw_saw.3.man \
	   ciaaw_ice.3.man \
	   ciaaw_naw.3.man \
	   ciaaw_nice.3.man \
	   ciaaw_nnaw.3.man \
	   ciaaw_ices.3.man \
	   ciaaw_s2z.3.man
MAN=$(patsubst %.man, %, $(MANSRC))
MANPDF=$(patsubst %, %.pdf, $(MAN))
MANTXT=$(patsubst %, %.txt, $(MAN))
MANGZ=$(patsubst %, %.gz, $(MAN))
MANHTML=$(patsubst %, %.html, $(MAN))

all: examples $(MAN) $(MANGZ) $(MANPDF) $(MANTXT) $(MANHTML)

examples: 
	./concatex

$(BOOKMAN): $(MANBUILD)
	bookman -p -a "$(FPM_AUTHOR)" -t $(FPM_NAME) -v "User Commands & Libary Functions Manual" -r $(FPM_VERSION) $(MAN) > $(BOOKMAN)

ciaaw_lib.3: ciaaw_lib.3.man
	cat $< examples.man seealso.man > tmp
	sed -E "s/@VERSION@/$(FPM_VERSION)/g;s/@DATE@/$(shell date +'%d %B %Y')/g" tmp > $@
	rm -rfv tmp

ciaaw_%.3: ciaaw_%.3.man
	cat $< seealso.man > tmp
	sed -E "s/@VERSION@/$(FPM_VERSION)/g;s/@DATE@/$(shell date +'%d %B %Y')/g" tmp > $@
	rm -rfv tmp

ciaaw.1: ciaaw.1.man
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
	rm -fv $(MAN) $(MANGZ) $(MANPDF) $(MANTXT) $(MANHTML)

