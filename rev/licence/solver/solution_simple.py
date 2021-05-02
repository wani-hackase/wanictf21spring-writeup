import angr

proj = angr.Project("./licence")
state = proj.factory.entry_state(args=["./licence", "key.dat"])
simgr = proj.factory.simulation_manager(state)
simgr.explore(find=0x405E6D, avoid=0x405E4B)

try:
    solution = simgr.found[0]
    print(solution.posix.dump_file_by_path("key.dat"))
except IndexError:
    print("Not Found")

"""
b'-----BEGIN LICENCE KEY-----\nFLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}\n-----END LICENCE KEY-----\n'
"""
