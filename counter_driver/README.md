# Single Counter Device Driver

This project is a simple virtual counter device driver that interacts with the `/proc` filesystem. The driver provides a single counter that can be incremented, decremented, reset, or set to a specific value through the `/proc` interface. This project demonstrates the basics of kernel module programming and how to interact with user space using the `/proc` filesystem.

## Project Structure

counter_driver/ 
├── Makefile 
├── src/ 
│ └── counter_driver.c 
├── include/ 
│ └── counter_driver.h (if needed) 
├── build/ 
│ └── (compiled .o and .ko files will go here) 
└── README.md

## Files

- `Makefile`: The main Makefile for building the kernel module.
- `src/counter_driver.c`: The source file containing the implementation of the counter device driver.
- `include/counter_driver.h`: Header file for the counter device driver (if needed).
- `build/`: Directory for compiled object files and the kernel module.
- `README.md`: Documentation for the project.

## Features

- Creates a `/proc` entry called `virtual_counter`.
- Allows incrementing, decrementing, resetting, and setting the value of the counter.
- Uses mutex locks for thread safety.

## Usage

1. **Build the Module**:

    Navigate to the root directory of your project and run:

    ```sh
    make
    ```

    This will compile the kernel module and place the compiled files in the `build/` directory.

2. **Load the Module**:

    Use `insmod` to load the module:

    ```sh
    sudo insmod build/counter_driver.ko
    ```

3. **Interact with the Counter**:

    - Increment Counter:
        ```sh
        echo inc > /proc/virtual_counter
        ```

    - Decrement Counter:
        ```sh
        echo dec > /proc/virtual_counter
        ```

    - Reset Counter:
        ```sh
        echo reset > /proc/virtual_counter
        ```

    - Set Counter to a Specific Value (e.g., 10):
        ```sh
        echo set 10 > /proc/virtual_counter
        ```

    - Check Counter Value:
        ```sh
        cat /proc/virtual_counter
        ```

4. **Unload the Module**:

    Use `rmmod` to unload the module:

    ```sh
    sudo rmmod counter_driver
    ```

5. **Clean the Build Files**:

    Run `make clean` to remove the generated build files:

    ```sh
    make clean
    ```

## Development

1. **Add New Features**:

    You can add new features or enhance existing ones by modifying the `src/counter_driver.c` file. For example, you can add more commands or implement additional functionalities.

2. **Compile and Test**:

    After making changes, compile the module using `make` and test it as described in the Usage section.

## License

This project is licensed under the GPL License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Linux Kernel Module Programming Guide
- Example codes from various open-source projects

---

Feel free to contribute or raise issues for further clarification!
