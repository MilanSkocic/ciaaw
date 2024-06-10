---
project: ciaaw
summary: Fortran library providing the standard atomic weights according to CIAAW.
project_github: https://github.com/MilanSkocic/ciaaw
project_download: https://github.com/MilanSkocic/ciaaw/releases
project_website: https://milanskocic.github.io/ciaaw-docs/index.html
author: Milan Skocic
email: milan.skocic@icloud.com
github: https://github.com/MilanSkocic
src_dir: ./src
include: ./include
media_dir: ./media/png
page_dir: ./doc
output_dir: API-doc
exclude_dir: ./example
             ./test
display: public
         protected
source: true
proc_internals: true
sort: permission-alpha
print_creation_date: true
md_extensions: markdown.extensions.toc
               markdown.extensions.smarty
fpp_extensions: fypp
preprocess: true
preprocessor: fypp
graph: true
graph_maxnodes: 250
graph_maxdepth: 5
coloured_edges: true
license: by-sa
favicon: media/ico/logo-ciaaw.ico
---

![Ciaaw](./media/logo-ciaaw.png)

[TOC]

{!README.md!}
