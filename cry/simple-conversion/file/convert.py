from const import flag


def bytes_to_integer(x: bytes) -> int:
    x = int.from_bytes(x, byteorder="big")
    return x


print(bytes_to_integer(flag))
