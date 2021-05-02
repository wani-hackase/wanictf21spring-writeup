from Crypto.Util.number import *

ans = long_to_bytes(7941081424088616006)[::-1]
ans += long_to_bytes(7311705455698409823)[::-1]
ans += long_to_bytes(3560223458505028963)[::-1]
ans += long_to_bytes(35295634984951667)[::-1]

print(ans)
# FLAG{c4n_y0u_execu4e_th1s_fi1e}
