savedcmd_/home/ubuntu/ldd/counter_driver/src/counter_driver.mod := printf '%s\n'   counter_driver.o | awk '!x[$$0]++ { print("/home/ubuntu/ldd/counter_driver/src/"$$0) }' > /home/ubuntu/ldd/counter_driver/src/counter_driver.mod
