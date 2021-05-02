logo = """
  .oooooo.   ooooo     ooo   .oooooo.    .oooooo..o
 d8P'  `Y8b  `888'     `8'  d8P'  `Y8b  d8P'    `Y8
888      888  888       8  888          Y88bo.
888      888  888       8  888           `"Y8888o.
888      888  888       8  888               `"Y88b
`88b    d88'  `88.    .8'  `88b    ooo  oo     .d8P
 `Y8bood8P'     `YbodP'     `Y8bood8P'  8""88888P'
"""
red = "\x1b[1;31m"
reset = "\x1b[0m"
description = f"""
╭─────────────────────╮
│ {red}1.{reset} Encrypt flag     │
│ {red}2.{reset} Encrypt          │
│ {red}3.{reset} Decrypt          │
│ {red}4.{reset} Show public key  │
│ {red}5.{reset} Exit             │
╰─────────────────────╯
""".strip()
flag = b"FLAG{OU_d0es_n0t_repre53nt_Osaka_University_but_Okamoto-Uchiyama}"
