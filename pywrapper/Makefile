ifeq ($(plat), )
	plat=linux
endif

DIRS=build dist *.egg-info
SETUP=setup.py pyproject.toml
PY_VERSIONS=3.8 3.9 3.10 3.11 3.12

all: build_inplace build_sdist build_wheel repair

build_inplace: build_inplace_$(plat)

build_sdist: build_sdist_$(plat)

build_wheel: build_wheel_$(plat)

repair: repair_$(plat)

test: build_inplace test_$(plat)




build_inplace_windows: setup.py
	$(foreach v,$(PY_VERSIONS),py -$(v) setup.py build_ext --inplace;)

build_inplace_linux: setup.py
	$(foreach v,$(PY_VERSIONS),python$(v) setup.py build_ext --inplace;)

build_inplace_darwin: 
	$(foreach v,$(PY_VERSIONS),python$(v) setup.py build_ext --inplace;)




build_sdist_windows: $(SETUP)
	py -3.12 -m build --no-isolation --sdist

build_sdist_linux: $(SETUP)
	python3.12 -m build --no-isolation --sdist

build_sdist_darwin: $(SETUP)
	python3.12 -m build --no-isolation --sdist
	



build_wheel_windows: $(SETUP)
	$(foreach v,$(PY_VERSIONS),py -$(v) -m build --no-isolation --wheel;)

build_wheel_linux: $(SETUP)
	$(foreach v,$(PY_VERSIONS),python$(v) -m build --no-isolation --wheel;)

build_wheel_darwin: $(SETUP)
	$(foreach v,$(PY_VERSIONS),python$(v) -m build --no-isolation --wheel;)




repair_windows:

repair_darwin:

repair_linux:
	cd ./dist
	auditwheel repair --plat manylinux_2_17_x86_64 *.whl
	cd ..



test_windows:
	$(foreach v,$(PY_VERSIONS),py -$(v) -m unittest -v;)

test_linux:
	$(foreach v,$(PY_VERSIONS),python$(v) -m unittest -v;)

test_darwin:
	$(foreach v,$(PY_VERSIONS),python$(v) -m unittest -v;)




clean: clean_$(plat)


clean_windows: 
	rd /s /q $(DIRS)

clean_linux: 
	rm -rf $(DIRS)

clean_darwin: 
	rm -rf $(DIRS)