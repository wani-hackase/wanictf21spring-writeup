import angr
import claripy

proj = angr.Project("./licence")

# シンボリックファイルの定義
filename = "key.dat"
data = claripy.BVS("data", 128 * 8)
simfile = angr.SimFile(filename, content=data)

# コマンドライン引数 "key.dat" を指定して、定義したシンボリックファイルを読み込む
state = proj.factory.entry_state(
    args=["./licence", "key.dat"],
    fs={filename: simfile},
)
simgr = proj.factory.simulation_manager(state)

# 到達したいアドレス、到達してほしくないアドレスを指定する
simgr.explore(find=0x405E6D, avoid=0x405E4B)

# 結果を表示する
try:
    solution = simgr.found[0]
    print(solution.posix.dump_file_by_path(filename))
except IndexError:
    print("Not Found")

"""
b'-----BEGIN LICENCE KEY-----\nFLAG{4n6r_15_4_5up3r_p0w3rfu1_5ymb0l1c_3x3cu710n_4n4ly515_700l}\n-----END LICENCE KEY-----\n\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
"""
