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

# Adding environment in notebook

> pip install ipykernel

> ipython kernel install --user --name=ml


# Uninstalling conda
1. Remove the entire Miniconda install directory with:
> rm -rf ~/miniconda

2. Edit ~/.bash_profile to remove the Miniconda directory from your PATH environment variable.

3. Remove the following hidden file and folders that may have been created in the home directory:
> rm -rf ~/.condarc ~/.conda ~/.continuum