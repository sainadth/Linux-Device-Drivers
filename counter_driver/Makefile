# Makefile for the single counter device driver

# The name of the module to be built
obj-m := counter_driver.o

# Directories
SRC_DIR := src
BUILD_DIR := build

# Path to the kernel source
KDIR := /lib/modules/$(shell uname -r)/build

# Current directory
PWD := $(shell pwd)

# Targets
all:
	$(MAKE) -C $(KDIR) M=$(PWD)/$(SRC_DIR) modules
	mkdir -p $(BUILD_DIR)
	mv -f $(SRC_DIR)/*.o $(SRC_DIR)/*.mod $(SRC_DIR)/*.mod.* $(SRC_DIR)/.counter_driver.* $(SRC_DIR)/*.ko $(BUILD_DIR)/ 2>/dev/null || true

clean:
	$(MAKE) -C $(KDIR) M=$(PWD)/$(SRC_DIR) clean
	rm -rf $(BUILD_DIR)/* $(BUILD_DIR)/.*

# Phony targets
.PHONY: all clean
