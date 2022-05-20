#!/bin/sh

export PATH=/opt/paraview/bin:"${PATH}"
export PYTHONPATH=/opt/paraview/lib/python@PYTHON@/site-packages/:"${PYTHONPATH}"
export LD_LIBRARY_PATH=/opt/paraview/lib/:"${LD_LIBRARY_PATH}"

exec /opt/paraview/bin/"$@"
