## Install Multipass

## Create a network instance

## Connect to the instance via vscode remote device connection

## Create file ldd.c and Makefile in a folder

## Build .ko file

```bash
make clean
make all
```

## Insert module into kernel

```bash
sudo insmod <ldd.ko>
```

## Additional commands

```bash
sudo modinfo <ldd>
```

## Remove module from kernel

```bash
sudo rmmod <ldd>
```
