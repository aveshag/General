# Installing miniconda
1. Download Miniconda installer for Linux.
[Click here](https://docs.conda.io/projects/conda/en/stable/user-guide/install/linux.html)

2. > bash Miniconda3-latest-Linux-x86_64.sh

# Installing jupyter notebook

> pip install notebook

> jupyter-notebook

# Installing extension for notebook

> pip install jupyter_contrib_nbextensions

> jupyter contrib nbextension install --user

# Creating environment

> conda create -n env-name python=3.9

> conda activate env-name

# Removing environment

> conda env remove -n env-name

# Adding environment in notebook

> pip install ipykernel

> ipython kernel install --user --name=ml

# Uninstalling conda
1. Remove the entire Miniconda install directory with:
> rm -rf ~/miniconda

2. Edit ~/.bash_profile to remove the Miniconda directory from your PATH environment variable.

3. Remove the following hidden file and folders that may have been created in the home directory:
> rm -rf ~/.condarc ~/.conda ~/.continuum

# Installing tensorflow with gpu support
[Link1](https://github.com/tensorflow/tensorflow/issues/57679)
[Link2](https://www.tensorflow.org/install/pip)

use python3.8 because tensorrt 8+ is not suppported for latest tensorflow
```
conda create -n ml python=3.8
conda activate ml
conda install -c conda-forge cudatoolkit=11.2 cudnn=8.1  
```
```
pip install --upgrade setuptools pip
pip install nvidia-pyindex
pip install nvidia-tensorrt==7.2.3.4
```
```
mkdir -p $CONDA_PREFIX/etc/conda/activate.d
echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CONDA_PREFIX/lib/' > $CONDA_PREFIX/etc/conda/activate.d/env_vars.sh
echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CONDA_PREFIX/lib/python3.8/site-packages/tensorrt/' >> $CONDA_PREFIX/etc/conda/activate.d/env_vars.sh
```
```
pip install tensorflow
```