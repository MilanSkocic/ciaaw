ifeq ($(PLATFORM), windows)
	PY=py -
endif
ifeq ($(PLATFORM), linux)
	PY=python
	AW=auditwheel repair --plat manylinux_2_17_x86_64 ./dist/*.whl
endif
ifeq ($(PLATFORM), darwin)
	PY=python
endif

SETUP=setup.py pyproject.toml

all: copy_h copy_shared python3.8 python3.9 python3.10 python3.11 python3.12

python3.12: $(SETUP)
	@echo "########### PYTHON 3.12 ##########"
	$(PY)3.12 setup.py build_ext --inplace
	$(PY)3.12 -m build --no-isolation --sdist
	$(PY)3.12 -m build --no-isolation --wheel
	$(PY)3.12 -m unittest -v
	$(AW)
	@echo "#################################"

python3.11: $(SETUP)
	@echo "########### PYTHON 3.11 ##########"
	$(PY)3.11 setup.py build_ext --inplace
	$(PY)3.11 -m build --no-isolation --wheel
	$(PY)3.11 -m unittest -v
	@echo "#################################"

python3.10: $(SETUP)
	@echo "########### PYTHON 3.10 ##########"
	$(PY)3.10 setup.py build_ext --inplace
	$(PY)3.10 -m build --no-isolation --wheel
	$(PY)3.10 -m unittest -v
	@echo "#################################"

python3.9: $(SETUP)
	@echo "########### PYTHON 3.9 ##########"
	$(PY)3.9 setup.py build_ext --inplace
	$(PY)3.9 -m build --no-isolation --wheel
	$(PY)3.9 -m unittest -v
	@echo "#################################"

python3.8: $(SETUP)
	@echo "########### PYTHON 3.8 ##########"
	$(PY)3.8 setup.py build_ext --inplace
	$(PY)3.8 -m build --no-isolation --wheel
	$(PY)3.8 -m unittest -v
	@echo "#################################"

copy_h: 
	cp -f $(LIB_INCLUDE_DIR)/$(HEADER_PREFIX)*.h $(PYW_SRC)/

copy_shared: copy_shared_$(PLATFORM)

copy_shared_linux:
	cp -f $(LIB_BUILD_DIR)/$(LIBNAME).so $(PYW_SRC)

copy_shared_darwin:
	cp -f $(LIB_BUILD_DIR)/$(LIBNAME).dylib $(PYW_SRC)

copy_shared_windows:
	cp -f $(LIB_BUILD_DIR)/$(LIBNAME).dll $(PYW_SRC)
	cp -f $(LIB_BUILD_DIR)/$(LIBNAME).dll.a $(PYW_SRC)

clean: 
	rm -rf build 
	rm -rf dist 
	rm -rf *.egg-info 
	rm -rf __pycache__ 
	rm -rf wheelhouse 
	rm -rf $(PYW_SRC)/__pycache__
	
	rm -f $(PYW_SRC)/$(HEADER_PREFIX)*.h 
	rm -f $(PYW_SRC)/$(LIBNAME)*.a 
	rm -f $(PYW_SRC)/$(LIBNAME)*.so 
	rm -f $(PYW_SRC)/$(LIBNAME)*.dylib 
	rm -f $(PYW_SRC)/$(LIBNAME)*.dll 
	rm -f $(PYW_SRC)/$(LIBNAME)*.dll.a 
	rm -f $(PYW_SRC)/$(LIBNAME)*.pyd

cleanall: clean

	rm -f $(PYW_SRC)/*.a 
	rm -f $(PYW_SRC)/*.so 
	rm -f $(PYW_SRC)/*.dylib 
	rm -f $(PYW_SRC)/*.dll 
	rm -f $(PYW_SRC)/*.dll.a 
	rm -f $(PYW_SRC)/*.pyd
