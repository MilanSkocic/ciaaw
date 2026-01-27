# 1.2.0

- Add CLI `ciaaw(1)` for searching saw, ice and naw.
- Code refactoring

[Full changelog](https://github.com/MilanSkocic/codata/releases)

# 1.1.1

* Refactoring the `configure.sh` script.
* Remove support for 3.14t. No official release on python.org.
* If binaries for Python 3.14t are needed you need to compile them by yourself.


# 1.1.0

* Remove support for Python 3.9 and add support for Python 3.14(t).

[Full changelog](https://github.com/MilanSkocic/ciaaw/releases)


# 1.0.0

* Switch to UCRT64 for Windows binaries.
* Switch documentation to `sphinx` with `fspx` (development version).
  * `fspx` uses Ford as a backend.
* Drop Ford documentation output

[Full changelog](https://github.com/MilanSkocic/ciaaw/releases)


# 0.5.1

* Code refactoring.
* Documentation update.

[Full changelog](https://github.com/MilanSkocic/ciaaw/releases)

# 0.5.0

* API break: 
    * Data for standard atomic weights are no directly accessed.
    * SAW, ICE and NAW are stored in derived types for each elements.
    * Each element is stored in a periodic table.
    * Element properties are now accessed through getters.
* Doc update.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


# 0.4.3 

* Refractoring.
* Documentation update.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


# 0.4.2 

* Refractoring.
* Documentation update.
* Merge back C API and Python wrapper.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


# 0.4.1

* Fix bug in max value for saw. 

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


# 0.4.0

* Fix type error in tests
* Refractoring
* Documentation update.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


# 0.3.0

* Code refactoring.
* Move C API and Python wrapper to their own repositories.
* Improve documentatinon.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)



# 0.2.0

* Fix error in phosphorus name.
* Possibility to have standard atomic weights for several years.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)



# 0.1.0

* All elements from the periodic table added for the saw module.
* They are implemented as parameter derived type.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)
