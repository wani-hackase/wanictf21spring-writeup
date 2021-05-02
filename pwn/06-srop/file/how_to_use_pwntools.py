# pwntools makes your pwn easier! (or possible)

from pwn import *  # if not installed : python3 -m pip install pwntools

# you can check what's going on at local
# At local you can use gdb to check whats happening

pc = process(
    "./pwn06"
)  # connect to pwn06 at the same directory. We will use 'pc' to control something related to your local pwn06.


# To get the flag, usually you should attack the remote
# At remote, you can't use gdb

ip = "111.111.111.111"  # input the ip address written in the question. It should be string.
portnumber = 1234  # port number written in the question. Should be integer
rm = connect(
    ip, portnumber
)  # connect to the remote process at the written ipaddress and port number. We will use 'rm' to control something related to the remote process.


# There are so many ways to communicate with the process including send and receive in pwntools check at  https://docs.pwntools.com/en/latest/tubes.html

local_string = pc.recvline()  # recv line from local process (byte type)
remote_string = rm.recvline()  # recv line from remote process (byte type)

print(
    "local_string > " + local_string.decode("utf-8")
)  # I usually use .decode('utf-8') to change from byte to string
print("remote_string > " + remote_string.decode("utf-8"))

payload_ex = p64(
    0x1111
)  # will pack your input(integer) to 64bit integer = you can put hex number of what you want into the memory in 64bit

gdb.attach(
    pc, "break main"
)  # Only available to local. gdb will turned on at this point. You can use just as your gdb. as you proceed at the gdb, the codes below this also automatically runs.
# Also you can put gdb instruction just like 'break main'
# May not work on WSL

pc.sendline(payload_ex)  # send data to local
rm.sendline(payload_ex)  # send data to remote
pc.interactive()  # Change to the user-interactive mode. Mainly used after getting a shell to access. You can and user input mode by ctrl+c
# red $ means your at interactive mode

# You will see "Got EOF while reading in interactive" This means exit of the process (Whatever the reason: error or not)

# You can try pwntools with the problem you solved!

# Good Luck!
